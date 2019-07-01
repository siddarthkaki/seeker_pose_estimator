#include "Utilities.h"

using Eigen::AngleAxisd;

Matrix3d Utilities::Euler2DCM_312(Vector3d eulVec)
{
    double phi   = eulVec(0);
    double theta = eulVec(1);
    double psi   = eulVec(2);

    Matrix3d DCM;
    DCM =   AngleAxisd( theta, Vector3d::UnitY() )*
            AngleAxisd(   phi, Vector3d::UnitX() )*
            AngleAxisd(   psi, Vector3d::UnitZ() );

    return DCM;
}

MatrixXd Utilities::FeaPointsTargetToChaser(VectorXd stateVec, Vector3d rCamVec, MatrixXd rFeaMat)
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

Vector2d Utilities::CameraProjection(Vector3d point3DVec, double f)
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

    if (~std::isfinite(x)) { x = 0; }
    if (~std::isfinite(y)) { x = 0; }

    Vector2d point2DVec;
    point2DVec << x, y;

    return point2DVec;
}

VectorXd Utilities::SimulateMeasurements(MatrixXd rMat, double focal_length)
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