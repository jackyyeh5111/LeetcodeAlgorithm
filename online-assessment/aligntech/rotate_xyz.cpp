#include <iostream>
#include <cmath>
#include <array>

// Function to perform matrix multiplication (3x3 matrix with 3x1 vector)
void matrixMultiply(const std::array<std::array<double, 3>, 3>& mat, double& x, double& y, double& z) {
    double result[3] = {0.0, 0.0, 0.0};
    double vec[3] = {x, y, z};

    // Perform matrix multiplication
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += mat[i][j] * vec[j];
        }
    }

    // Update x, y, z
    x = result[0];
    y = result[1];
    z = result[2];
}

// Function to rotate a point (x, y, z) around the X, Y, Z axes by given angles
void rotatePoint(double& x, double& y, double& z, double thetaX, double thetaY, double thetaZ) {
    // Convert angles from degrees to radians
    double radX = thetaX * M_PI / 180.0;
    double radY = thetaY * M_PI / 180.0;
    double radZ = thetaZ * M_PI / 180.0;

    // Rotation matrix for the X-axis
    std::array<std::array<double, 3>, 3> R_x = {{
        {1, 0, 0},
        {0, cos(radX), -sin(radX)},
        {0, sin(radX), cos(radX)}
    }};

    // Rotation matrix for the Y-axis
    std::array<std::array<double, 3>, 3> R_y = {{
        {cos(radY), 0, sin(radY)},
        {0, 1, 0},
        {-sin(radY), 0, cos(radY)}
    }};

    // Rotation matrix for the Z-axis
    std::array<std::array<double, 3>, 3> R_z = {{
        {cos(radZ), -sin(radZ), 0},
        {sin(radZ), cos(radZ), 0},
        {0, 0, 1}
    }};

    // Apply Z rotation
    matrixMultiply(R_z, x, y, z);

    // Apply Y rotation
    matrixMultiply(R_y, x, y, z);

    // Apply X rotation
    matrixMultiply(R_x, x, y, z);
}

int main() {
    // Original point (x, y, z)
    double x = 1.0, y = 1.0, z = 1.0;

    // Rotation angles in degrees for x, y, z axes
    double thetaX = 30.0;  // Rotate 30 degrees around x-axis
    double thetaY = 45.0;  // Rotate 45 degrees around y-axis
    double thetaZ = 60.0;  // Rotate 60 degrees around z-axis

    // Rotate the point
    rotatePoint(x, y, z, thetaX, thetaY, thetaZ);

    // Output the rotated point
    std::cout << "Rotated Point: (" << x << ", " << y << ", " << z << ")" << std::endl;

    return 0;
}
