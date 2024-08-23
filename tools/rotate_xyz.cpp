#include <iostream>
#include <vector>
#include <cmath>

// Define a structure to hold 3D points
struct Point3D {
    double x;
    double y;
    double z;
};

// Function to rotate a point around the z-axis by 90 degrees
Point3D rotateZ90(const Point3D& point, double angle) {
    /* 
        Rxy = [[cosX, -sinX, 0],
               [sinX,  cosX, 0],
               [0.  , 0.   , 1]]
     */
    Point3D rotatedPoint;
    double cosAngle = std::cos(angle);
    double sinAngle = std::sin(angle);
    
    rotatedPoint.x = cosAngle * point.x - sinAngle * point.y;
    rotatedPoint.y = sinAngle * point.x + cosAngle * point.y;
    rotatedPoint.z = point.z;
    return rotatedPoint;
}

int main() {
    // Define a vector of 3D points
    std::vector<Point3D> points = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    std::vector<Point3D> rotatedPoints;
    rotatedPoints.reserve(points.size());

    // Rotate each point and store the result
    double degree = 90.0;
    double radian = degree * M_PI  / 180.f ;
    for (const auto& point : points) {
        rotatedPoints.push_back(rotateZ90(point, radian));
    }

    // Output the rotated points
    for (const auto& point : rotatedPoints) {
        std::cout << "Rotated Point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }

    return 0;
}
