#include "Utilities.h"

using Eigen::AngleAxisd;
using Eigen::Quaterniond;

/**
 * @function Euler2DCM_312
 * @brief Converts euler angles phi, theta, psi (RPY) to DCM with 3-1-2 rotation
 * @return DCM corresponding to 3-1-2 euler angle rotation
 */
Matrix3d Utilities::Euler2DCM_312(const Vector3d& eulVec)
{
    //double phi   = eulVec(0);
    //double theta = eulVec(1);
    //double psi   = eulVec(2);

    Matrix3d DCM;
    DCM =   AngleAxisd( eulVec(1), Vector3d::UnitY() ).toRotationMatrix().transpose()*
            AngleAxisd( eulVec(0), Vector3d::UnitX() ).toRotationMatrix().transpose()*
            AngleAxisd( eulVec(2), Vector3d::UnitZ() ).toRotationMatrix().transpose();

    return DCM;
}

/**
 * @function DCM2Euler_312
 * @brief Converts DCM to euler angles phi, theta, psi (RPY) representing 3-1-2 rotation
 * @return Euler angles corresponding to 3-1-2 rotation
 */
Vector3d Utilities::DCM2Euler_312(const MatrixXd& DCM)
{
    double phi = asin( DCM(1,2) );

    double theta = atan2( -DCM(0,2), DCM(2,2) );

    double psi = atan2( -DCM(1,0), DCM(1,1) );

    Vector3d eulVec;
    eulVec << phi, theta, psi;

    return eulVec;
}

/**
 * @function FeaPointsTargetToChaser
 * @brief Transforms feature points in target frame wrt target to chaser frame wrt chaser
 * @return MatrixXd of feature points in chaser frame wrt chaser
 */
MatrixXd Utilities::FeaPointsTargetToChaser(const VectorXd& stateVec, const Vector3d& rCamVec, const MatrixXd& rFeaMat)
{
    // DCM from target frame to chaser frame
    Vector3d relVec = stateVec.segment(0,3); // extract first three elements of state
    Vector3d eulVec = stateVec.segment(3,3); // extract last three elements of state
    Matrix3d DCM = Euler2DCM_312(eulVec); // 3-1-2 sequence

    unsigned int numPts = rFeaMat.rows(); // number of feature points

    MatrixXd rMat_c = MatrixXd::Zero(numPts, 3);

    for (unsigned int idx = 0; idx < numPts; idx++)
    {
        Vector3d rFeaVeci = rFeaMat.row(idx);
        Vector3d rFeaVeci_c = DCM*rFeaVeci;

        // position vector of feature point i wrt chaser in chaser frame
        Vector3d rVeci = relVec - rCamVec + rFeaVeci_c;

        rMat_c.row(idx) = rVeci.transpose();
    }

    return rMat_c;
}

/**
 * @function CameraProjection
 * @brief Performs simple camera projection of 3D point to image plane
 * @return Vector2d of projected 2D point
 */
Vector2d Utilities::CameraProjection(const Vector3d& point3DVec, const double& f)
{
    MatrixXd PMat(3,4);
    PMat << f, 0, 0, 0,
            0, f, 0, 0,
            0, 0, 1, 0;

    VectorXd homoFeaPtVec(4);
    homoFeaPtVec << point3DVec,
                    1;

    Vector3d projVec = PMat*homoFeaPtVec;

    double x = projVec(0)/projVec(2);
    double y = projVec(1)/projVec(2);

    if (!std::isfinite(x)) { x = 0; }
    if (!std::isfinite(y)) { y = 0; }

    Vector2d point2DVec;
    point2DVec << x, y;

    return point2DVec;
}

/**
 * @function SimulateMeasurements
 * @brief Simulates measurements from given pose
 * @return VectorXd of measurements
 */
VectorXd Utilities::SimulateMeasurements(const MatrixXd& rMat, const double& focal_length)
{
    unsigned int numPts = rMat.rows();
   
    // project feature points to image plane
    MatrixXd imgPtMat = MatrixXd::Zero(numPts, 2);
    for (unsigned int idx = 0; idx < numPts; idx++)
    {
        Vector3d rVeci = rMat.row(idx);//.transpose;
        Vector2d imgPti = CameraProjection(rVeci,focal_length);
        imgPtMat.row(idx) = imgPti.transpose();
    }

    // azimuth & elevation measurements for feature points
    VectorXd azVec = VectorXd::Zero(numPts);
    VectorXd elVec = VectorXd::Zero(numPts);
    for (unsigned int idx = 0; idx < numPts; idx++)
    {
        Vector2d imgPti = imgPtMat.row(idx);
        
        azVec(idx) = atan2(imgPti(0),focal_length);
        elVec(idx) = atan2(imgPti(1),focal_length);
    }

    VectorXd yVec(numPts*2); // vector of measurements
    for (unsigned int idx = 0; idx < numPts; idx++)
    {
        yVec(idx*2+0) = azVec(idx);
        yVec(idx*2+1) = elVec(idx);
    }

    return yVec;
}

/**
 * @function AddGaussianNoiseToVector
 * @brief Adds zero-mean Gaussian noise with provided std to VectorXd
 * @return Input VectorXd values with additive Gaussian noise
 */
VectorXd Utilities::AddGaussianNoiseToVector(const VectorXd& vec, const double& std)
{
    const unsigned int numMeas = vec.size();

    MatrixXd covarMat = pow(std,2)*MatrixXd::Identity(numMeas, numMeas);

    Eigen::EigenMultivariateNormal<double> normX_solver(vec, covarMat);
    
    VectorXd vecNoise = normX_solver.samples(1);

    return vecNoise;
}

/**
 * @function ConjugatePose
 * @brief Finds the so-called "conjugate pose" for a given pose
 * @return VectorXd of conjugate pose
 */
VectorXd Utilities::ConjugatePose(const VectorXd& stateVec)
{
    Matrix3d DCMHat = Euler2DCM_312(stateVec.tail(3));

    Vector3d p0 = DCMHat*Vector3d::Zero();
    Vector3d p1 = DCMHat*Vector3d::UnitZ();
    Vector3d p2 = DCMHat*Vector3d::UnitY();

    Vector3d p01 = p1 - p0;
    Vector3d p02 = p2 - p0;
    Vector3d n = p01.cross(p02);
    
    if ( n(2) < 0 ) { n = -n; }

    double phi  = acos( n.dot(Vector3d::UnitZ())/n.norm() );
    Vector3d aHat = n.cross(Vector3d::UnitZ()).normalized();

    MatrixXd DCMHat2 = AngleAxisd( -2*phi, aHat ).toRotationMatrix().transpose()*DCMHat;
    
    VectorXd stateVecConj = stateVec;
    stateVecConj.tail(3) = DCM2Euler_312(DCMHat2);

    return stateVecConj;
}

/**
 * @function PositionScore
 * @brief Computes the position score for a position state estimate
 * @return Position score value for provided state estimate
 */
double Utilities::PositionScore(const VectorXd& stateVec, const VectorXd& stateHatVec)
{
    Vector3d posVec = stateVec.head(3);
    Vector3d posHatVec = stateHatVec.head(3);

    Vector3d posErrVec = posVec - posHatVec;

    double pos_score = posErrVec.squaredNorm()/posVec.squaredNorm();
    return pos_score;
}

/**
 * @function AttitudeScore
 * @brief computes the attitude score for an attitude state estimate
 * @return Attitude score value for provided state estimate
 */
double Utilities::AttitudeScore(const VectorXd& stateVec, const VectorXd& stateHatVec)
{
    Vector3d eulVec = stateVec.tail(3);
    Vector3d eulHatVec = stateHatVec.tail(3);

    Matrix3d DCM = Euler2DCM_312(eulVec);
    Matrix3d DCMHat = Euler2DCM_312(eulHatVec);

    Quaterniond qVec = Quaterniond(DCM);
    Quaterniond qHatVec = Quaterniond(DCMHat);

    qVec.normalize();
    qHatVec.normalize();

    Quaterniond dqVec = qVec*qHatVec.inverse();

    double att_score = 2*acos( std::abs( dqVec.w() ) );
    return att_score;
}