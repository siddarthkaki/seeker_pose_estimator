#include <Eigen/Core>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <math.h>

#include "ceres/ceres.h"
//#include "glog/logging.h"

#include "cost_functor.h"
#include "Utilities.h"
#include "PoseSolver.h"

#include "third_party/json.hpp"
#include "third_party/KalmanFilter/KalmanFilter.h"
//#include "third_party/matplotlibcpp/matplotlibcpp.h"

using Eigen::Vector3d;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Vector3d;
using Eigen::Quaterniond;
using Eigen::AngleAxisd;
using nlohmann::json;

#define GET_VARIABLE_NAME(Variable) (#Variable)
//void PlotPoseTrajectory(const std::vector<Pose>& poses, const double& dt);

/**
 * @function main
 * @brief main function
 */
int main(int argc, char** argv)
{

    //google::InitGoogleLogging(argv[0]);

    //-- Read-in problem geometry and params ---------------------------------/

    // read params from JSON file
    std::ifstream input_stream("../params.json");
    json json_params;
    input_stream >> json_params;

    // specify rigid position vector of camera wrt chaser in chaser frame
    Vector3d rCamVec;
    for (unsigned int idx = 0; idx < 2; idx++)
    { rCamVec(idx) = json_params["rCamVec"].at(idx); }

    // specify camera focal length
    double focal_length = json_params["focal_length"];//5.5*pow(10,-3);

    // specify measurement noise standard deviation (rad)
    double meas_std = double(json_params["meas_std_deg"])*Utilities::DEG2RAD;

    // specify rigid position vector of feature points wrt target in target frame
    unsigned int num_features = json_params["rFeaMat"].size();
    MatrixXd rFeaMat(num_features,3);
    for (unsigned int idx = 0; idx < num_features; idx++)
    {   for (unsigned int jdx = 0; jdx < 3; jdx++)
        { rFeaMat(idx,jdx) = json_params["rFeaMat"][idx]["fea" + std::to_string(idx+1)][jdx]; } }
    
    unsigned int num_poses_test = json_params["num_poses_test"];

    //------------------------------------------------------------------------/

    // initial pose guess
    Pose pose0;
    pose0.pos <<  0.0, 0.0, 25.0;
    pose0.quat.w() = 1.0;
    pose0.quat.vec() = Vector3d::Zero();

    //-- Loop ----------------------------------------------------------------/

    //-- KF init --//
    KF::KalmanFilter kf;
    double kf_process_noise_std = 0.001;
    double kf_measurement_noise_std = 0.05;
    double kf_dt = 0.0005;
    kf.InitLinearPoseTracking(kf_process_noise_std, kf_measurement_noise_std, kf_dt);
    VectorXd state0 = VectorXd::Zero(kf.num_states_);
    state0.head(6) << 0.0, 0.0, 25.0, 0.0, 0.0, 0.0;
    MatrixXd covar0 = MatrixXd::Identity(kf.num_states_, kf.num_states_);
    kf.SetInitialStateAndCovar(state0, covar0);
    //-------------//

    std::vector<Pose> true_poses, solved_poses, solved_poses_conj, filtered_poses;
    std::vector<double> solution_times; // [ms]
    std::vector<double> pos_scores;
    std::vector<double> att_scores;

    true_poses.reserve(num_poses_test);
    solved_poses.reserve(num_poses_test);
    solved_poses_conj.reserve(num_poses_test);
    filtered_poses.reserve(num_poses_test);
    solution_times.reserve(num_poses_test);
    pos_scores.reserve(num_poses_test);
    att_scores.reserve(num_poses_test);

    Pose pose_true;
    pose_true.pos << 0.0, 0.0, 25.0;
    pose_true.quat = Quaterniond::UnitRandom();
    //true_poses.push_back(pose_true);
    //pose_true.quat.w() = 1.0;
    //pose_true.quat.vec() = Vector3d::Zero();

    for (unsigned int pose_idx = 0; pose_idx < num_poses_test; pose_idx++)
    {
        //-- Simulate Measurements -------------------------------------------/

        // generate true pose values for ith run
        pose_true.pos += Vector3d::Ones()*0.05;
        Quaterniond quat_step = AngleAxisd( 0.01, Vector3d::UnitX() )*
                                AngleAxisd( 0.01, Vector3d::UnitY() )*
                                AngleAxisd( 0.01, Vector3d::UnitZ() );
        pose_true.quat = pose_true.quat*quat_step;

        // express feature points in chaser frame at the specified pose
        MatrixXd rMat = Utilities::FeaPointsTargetToChaser(pose_true, rCamVec, rFeaMat);

        // generate simulated measurements
        VectorXd yVec = Utilities::SimulateMeasurements(rMat, focal_length);

        // add Gaussian noise to simulated measurements
        VectorXd yVecNoise = Utilities::AddGaussianNoiseToVector(yVec, meas_std);

        //--------------------------------------------------------------------/

        //-- Solve for pose --------------------------------------------------/

        // timing
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

        // solve for pose with ceres (via wrapper)
        PoseSolution pose_sol = PoseSolver::SolvePoseReinit(pose0, yVecNoise, rCamVec, rFeaMat);

        Pose conj_pose_temp = Utilities::ConjugatePose(pose_sol.pose);
        Pose conj_pose = PoseSolver::SolvePose(conj_pose_temp, yVecNoise, rCamVec, rFeaMat).pose;

        // KF tracking
        VectorXd pose_meas_wrapper(6);
        pose_meas_wrapper.head(3) = pose_sol.pose.pos;
        pose_meas_wrapper.tail(3) = pose_sol.pose.quat.toRotationMatrix().eulerAngles(0, 1, 2);
        kf.KFStep(pose_meas_wrapper);
        VectorXd pose_filt_wrapper = kf.states.back().head(6);
        Pose pose_filtered;
        pose_filtered.pos  = pose_filt_wrapper.head(3);
        pose_filtered.quat = AngleAxisd(pose_filt_wrapper(3), Vector3d::UnitX())*
                             AngleAxisd(pose_filt_wrapper(4), Vector3d::UnitY())*
                             AngleAxisd(pose_filt_wrapper(5), Vector3d::UnitZ());

        // timing
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        
        // time taken to perform NLS solution
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
        //--------------------------------------------------------------------/

        //-- Performance Metrics & Storage -----------------------------------/

        // compute position and attitude scores
        double      pos_score = Utilities::PositionScore(pose_true.pos , pose_filtered.pos );
        double      att_score = Utilities::AttitudeScore(pose_true.quat, pose_filtered.quat);
        //double conj_att_score = Utilities::AttitudeScore(pose_true.quat,    conj_pose.quat);

        // store info from ith run
        true_poses.push_back( pose_true );
        solved_poses.push_back( pose_sol.pose );
        solved_poses_conj.push_back( conj_pose );
        filtered_poses.push_back( pose_filtered );
        solution_times.push_back( (double)duration );
        pos_scores.push_back( pos_score );
        att_scores.push_back( att_score ); //std::min(att_score,conj_att_score) );

    }

    //-- Performance Metric Stats & Output -----------------------------------/

    //PlotPoseTrajectory(solved_poses, kf_dt);

    // write to csv file
    Utilities::WritePosesToCSV(true_poses, Utilities::WrapVarToPath(std::string(GET_VARIABLE_NAME(true_poses))));
    Utilities::WritePosesToCSV(solved_poses, Utilities::WrapVarToPath(std::string(GET_VARIABLE_NAME(solved_poses))));
    Utilities::WritePosesToCSV(filtered_poses, Utilities::WrapVarToPath(std::string(GET_VARIABLE_NAME(filtered_poses))));


    double pos_score_mean = Utilities::StdVectorMean(pos_scores);
    double att_score_mean = Utilities::StdVectorMean(att_scores);

    double pos_score_std = sqrt(Utilities::StdVectorVar(pos_scores));
    double att_score_std = sqrt(Utilities::StdVectorVar(att_scores));

    double solution_times_mean = Utilities::StdVectorMean(solution_times);

    std::cout << "num_runs :\t" << num_poses_test << std::endl << std::endl;

    std::cout << "pos_score_mean :\t" << pos_score_mean << /*" [m]" <<*/ std::endl;
    std::cout << "pos_score_std  :\t" << pos_score_std  << /*" [m]" <<*/ std::endl << std::endl;

    std::cout << "att_score_mean :\t" << att_score_mean*Utilities::RAD2DEG << " [deg]" << std::endl;
    std::cout << "att_score_std  :\t" << att_score_std*Utilities::RAD2DEG  << " [deg]" << std::endl << std::endl;

    std::cout << "mean_time  :\t" << solution_times_mean << " [ms]" << std::endl;
    std::cout << "total_time :\t" << solution_times_mean*num_poses_test << " [ms]" << std::endl;
    //------------------------------------------------------------------------/

    return 0;
}


/*
void PlotPoseTrajectory(const std::vector<Pose>& poses, const double& dt)
{
    unsigned int num_poses = poses.size();
    std::vector<double> x, y, z, phi, theta, psi, time;
    x.reserve(num_poses);
    y.reserve(num_poses);
    z.reserve(num_poses);
    phi.reserve(num_poses);
    theta.reserve(num_poses);
    psi.reserve(num_poses);
    time.reserve(num_poses);
    time.push_back(0.0);
    
    for (Pose pose : poses)
    {
        Vector3d posVec = pose.pos;
        Vector3d eulVec = pose.quat.toRotationMatrix().eulerAngles(0, 1, 2);
        x.push_back(posVec(0));
        y.push_back(posVec(1));
        z.push_back(posVec(2));
        phi.push_back(eulVec(0));
        theta.push_back(eulVec(1));
        psi.push_back(eulVec(2));
        time.push_back( time.back() + dt );
    }

    time.pop_back();

    namespace plt = matplotlibcpp;
    
    
    plt::figure_size(1200, 780);
    
    plt::named_plot("x", time, x, "b");
    plt::named_plot("y", time, y, "r");
    plt::named_plot("z", time, z, "g");
    // Set x-axis to interval [0,1000000]
    plt::xlim(0.0, time.back()+dt);
    // Add graph title
    plt::title("Sample figure");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./basic.png");
}
*/