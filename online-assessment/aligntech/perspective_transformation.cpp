#include <iostream>
#include <vector>

struct Point3D {
    double x, y, z;
};

struct Point2D {
    double u, v;
};

// Perspective Transformation Function
std::vector<Point2D> projectPoints(const std::vector<Point3D>& points3D,
                                   const std::vector<std::vector<double>>& K,
                                   const std::vector<std::vector<double>>& R,
                                   const std::vector<double>& t) {
    std::vector<Point2D> points2D;

    for (const auto& p : points3D) {
        // Transform point to camera coordinates
        double X_c = R[0][0] * p.x + R[0][1] * p.y + R[0][2] * p.z + t[0];
        double Y_c = R[1][0] * p.x + R[1][1] * p.y + R[1][2] * p.z + t[1];
        double Z_c = R[2][0] * p.x + R[2][1] * p.y + R[2][2] * p.z + t[2];

        // Project to image coordinates
        double u_prime = K[0][0] * X_c + K[0][2] * Z_c;
        double v_prime = K[1][1] * Y_c + K[1][2] * Z_c;
        double w = Z_c;

        // Normalize to get pixel coordinates
        double u = u_prime / w;
        double v = v_prime / w;

        points2D.push_back({u, v});
    }

    return points2D;
}

int main() {
    // 3D points
    std::vector<Point3D> points3D = {{1, 2, 5}, {2, 3, 6}, {0, 0, 10}};

    // Camera intrinsics
    std::vector<std::vector<double>> K = {
        {1000, 0, 320},
        {0, 1000, 240},
        {0, 0, 1}
    };

    // Camera rotation (identity for simplicity)
    std::vector<std::vector<double>> R = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Camera translation
    std::vector<double> t = {0, 0, -5};

    // Project points
    auto points2D = projectPoints(points3D, K, R, t);

    // Output 2D points
    for (const auto& p : points2D) {
        std::cout << "Projected Point: (" << p.u << ", " << p.v << ")\n";
    }

    return 0;
}
