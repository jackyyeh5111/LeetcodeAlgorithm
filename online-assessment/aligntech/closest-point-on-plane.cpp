#include <iostream>
#include <cmath>

struct Point {
    double x, y, z;
};

// Function to subtract two points (vector subtraction)
Point subtract(const Point& p1, const Point& p2) {
    return {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z};
}

// Function to compute the dot product of two points (vectors)
double dotProduct(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

// Function to scale a point (multiply vector by scalar)
Point scale(const Point& p, double scalar) {
    return {p.x * scalar, p.y * scalar, p.z * scalar};
}

// Function to project a point onto a plane
Point projectPointOntoPlane(const Point& P, const Point& P_plane, const Point& normal) {
    // Compute the vector from the point to the point on the plane
    Point vec = subtract(P, P_plane);
    
    // Compute the dot product of the vector and the plane's normal
    double dotVecNormal = dotProduct(vec, normal);
    
    // Compute the dot product of the normal vector with itself
    double dotNormalNormal = dotProduct(normal, normal);
    
    // Compute the projection of the vector onto the normal
    double factor = dotVecNormal / dotNormalNormal;
    
    // Calculate the projection and subtract from the point to get the projected point
    Point projection = scale(normal, factor);
    Point projectedPoint = subtract(P, projection);
    
    return projectedPoint;
}

int main() {
    // Define a point and a point on the plane
    Point P = {2.0, 3.0, 4.0};  // Point to project
    Point P_plane = {1.0, 1.0, 1.0};  // A point on the plane
    Point normal = {1.0, -2.0, 1.0};  // Normal to the plane (A, B, C)

    // Project the point onto the plane
    Point projectedPoint = projectPointOntoPlane(P, P_plane, normal);
    
    // Output the result
    std::cout << "Projected point: (" 
              << projectedPoint.x << ", " 
              << projectedPoint.y << ", " 
              << projectedPoint.z << ")\n";
    
    return 0;
}
