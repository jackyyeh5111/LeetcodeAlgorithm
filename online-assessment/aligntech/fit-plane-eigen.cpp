#include <iostream>
#include <vector>
#include <Eigen/Dense>

struct Point3D {
    double x, y, z;
};

// Function to compute the plane coefficients (ax + by + cz + d = 0)
Eigen::Vector4d fitPlane(const std::vector<Point3D>& points) {
    int n = points.size();
    if (n < 3) {
        throw std::invalid_argument("At least 3 points are required to fit a plane.");
    }

    // Formulate the matrices for least squares fitting
    Eigen::MatrixXd A(n, 3); // Matrix for point coordinates
    Eigen::VectorXd b(n);    // Vector of all ones (for d)

    for (int i = 0; i < n; ++i) {
        A(i, 0) = points[i].x;
        A(i, 1) = points[i].y;
        A(i, 2) = 1.0;  // For the constant term
        b(i) = -points[i].z; // Move z to the right-hand side
    }

    // Solve the linear system A * [a, b, d]^T = b for plane coefficients
    Eigen::Vector3d solution = A.colPivHouseholderQr().solve(b);

    // Extract coefficients: a, b, d
    double a = solution(0);
    double b_coeff = solution(1);
    double d = solution(2);

    // Compute c (normalize normal vector)
    double c = -1.0; // Implicit since we solved for -z

    return Eigen::Vector4d(a, b_coeff, c, d);
}

int main() {
    // Example points
    std::vector<Point3D> points = {
        {1.0, 2.0, 3.0},
        {2.0, 3.0, 5.0},
        {3.0, 4.0, 6.0},
        {4.0, 5.0, 7.0}
    };

    try {
        Eigen::Vector4d plane = fitPlane(points);
        std::cout << "Fitted Plane Equation: "
                  << plane[0] << "x + "
                  << plane[1] << "y + "
                  << plane[2] << "z + "
                  << plane[3] << " = 0" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
