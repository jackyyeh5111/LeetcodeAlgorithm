#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

// A 3D point representation
struct Point3D {
    double x, y, z;
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
};

// A face of the convex hull, defined by three vertices (indices of points in the input)
struct Face {
    int a, b, c; // indices of points
    Face(int a, int b, int c) : a(a), b(b), c(c) {}
};

// Cross product of two 3D vectors
Point3D crossProduct(const Point3D& u, const Point3D& v) {
    return Point3D(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}

// Dot product of two 3D vectors
double dotProduct(const Point3D& u, const Point3D& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

// Vector subtraction
Point3D subtract(const Point3D& u, const Point3D& v) {
    return Point3D(u.x - v.x, u.y - v.y, u.z - v.z);
}

// Distance from a point to a plane defined by three points (a, b, c)
double pointToPlaneDistance(const Point3D& p, const Point3D& a, const Point3D& b, const Point3D& c) {
    Point3D ab = subtract(b, a);
    Point3D ac = subtract(c, a);
    Point3D normal = crossProduct(ab, ac);
    Point3D ap = subtract(p, a);
    return fabs(dotProduct(normal, ap)) / sqrt(dotProduct(normal, normal));
}

// Recursive function to find faces of the convex hull
void findHull(const vector<Point3D>& points, int a, int b, int c, vector<Face>& faces, set<int>& visited) {
    double maxDistance = 0;
    int farthestPoint = -1;

    // Find the farthest point from the current face (a, b, c)
    for (int i = 0; i < points.size(); i++) {
        if (visited.count(i)) continue; // Skip already processed points
        double distance = pointToPlaneDistance(points[i], points[a], points[b], points[c]);
        if (distance > maxDistance) {
            maxDistance = distance;
            farthestPoint = i;
        }
    }

    if (farthestPoint == -1) {
        // No point is outside this face; it's part of the convex hull
        faces.emplace_back(a, b, c);
        return;
    }

    // Mark the farthest point as visited
    visited.insert(farthestPoint);

    // Recurse for the three new faces formed with the farthest point
    findHull(points, a, b, farthestPoint, faces, visited);
    findHull(points, b, c, farthestPoint, faces, visited);
    findHull(points, c, a, farthestPoint, faces, visited);
}

// Main algorithm: Quickhull for 3D convex hull
void quickHull3D(const vector<Point3D>& points, vector<Face>& faces) {
    if (points.size() < 4) {
        cerr << "Convex hull requires at least 4 non-coplanar points.\n";
        return;
    }

    // Find extreme points along the x-axis
    int min_x = 0, max_x = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < points[min_x].x) min_x = i;
        if (points[i].x > points[max_x].x) max_x = i;
    }

    // Find a point with maximum distance from the line (min_x, max_x)
    double maxDistance = 0;
    int farthestPoint = -1;
    for (int i = 0; i < points.size(); i++) {
        if (i == min_x || i == max_x) continue;
        double distance = pointToPlaneDistance(points[i], points[min_x], points[max_x], Point3D(0, 0, 0));
        if (distance > maxDistance) {
            maxDistance = distance;
            farthestPoint = i;
        }
    }

    if (farthestPoint == -1) {
        cerr << "All points are collinear.\n";
        return;
    }

    // Add these three points to the hull base
    set<int> visited = {min_x, max_x, farthestPoint};

    // Process the initial triangular base (min_x, max_x, farthestPoint)
    findHull(points, min_x, max_x, farthestPoint, faces, visited);
    findHull(points, max_x, farthestPoint, min_x, faces, visited);
    findHull(points, farthestPoint, min_x, max_x, faces, visited);
}

// Example usage
int main() {
    vector<Point3D> points = {
        {0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
        {1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}
    };

    vector<Face> faces;
    quickHull3D(points, faces);

    cout << "Convex Hull Faces:\n";
    for (const auto& face : faces) {
        cout << "(" << face.a << ", " << face.b << ", " << face.c << ")\n";
    }

    return 0;
}
