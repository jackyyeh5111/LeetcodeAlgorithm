#include <iostream>
#include <cmath>
#include <limits>

struct Point {
    double x, y, z;
};

// Vector operations
Point subtract(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

double dotProduct(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point crossProduct(const Point& a, const Point& b) {
    return {a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
}

// Clamp a value between min and max
double clamp(double value, double min, double max) {
    return std::max(min, std::min(max, value));
}

// Project a point onto a line segment
Point closestPointOnSegment(const Point& p, const Point& a, const Point& b) {
    Point ab = subtract(b, a);
    double t = dotProduct(subtract(p, a), ab) / dotProduct(ab, ab);
    t = clamp(t, 0.0, 1.0);
    return {a.x + t * ab.x, a.y + t * ab.y, a.z + t * ab.z};
}

// Closest point on triangle
Point closestPointOnTriangle(const Point& p, const Point& a, const Point& b, const Point& c) {
    // Compute vectors
    Point ab = subtract(b, a);
    Point ac = subtract(c, a);
    Point ap = subtract(p, a);

    // Compute triangle normal
    Point normal = crossProduct(ab, ac);

    // Compute barycentric coordinates
    double area2 = dotProduct(normal, normal); // Twice the area squared
    if (area2 == 0.0) {
        // Degenerate triangle, return any vertex
        return a;
    }

    // Check if the point is inside the triangle
    Point bc = subtract(c, b);
    Point bp = subtract(p, b);
    double alpha = dotProduct(crossProduct(bc, bp), normal) / area2;
    double beta = dotProduct(crossProduct(ap, ac), normal) / area2;
    double gamma = 1.0 - alpha - beta;

    if (alpha >= 0 && beta >= 0 && gamma >= 0) {
        // Point is inside the triangle
        return {a.x * alpha + b.x * beta + c.x * gamma,
                a.y * alpha + b.y * beta + c.y * gamma,
                a.z * alpha + b.z * beta + c.z * gamma};
    }

    // Otherwise, find the closest point on the edges
    Point closestAB = closestPointOnSegment(p, a, b);
    Point closestBC = closestPointOnSegment(p, b, c);
    Point closestCA = closestPointOnSegment(p, c, a);

    // Find the closest point among these
    double distAB = dotProduct(subtract(p, closestAB), subtract(p, closestAB));
    double distBC = dotProduct(subtract(p, closestBC), subtract(p, closestBC));
    double distCA = dotProduct(subtract(p, closestCA), subtract(p, closestCA));

    if (distAB <= distBC && distAB <= distCA) return closestAB;
    if (distBC <= distAB && distBC <= distCA) return closestBC;
    return closestCA;
}

int main() {
    // Define the triangle vertices
    Point a = {0, 0, 0};
    Point b = {1, 0, 0};
    Point c = {0, 1, 0};

    // Define the point
    Point p = {0.3, 0.3, 1};

    // Find the closest point on the triangle
    Point closest = closestPointOnTriangle(p, a, b, c);

    // Output the result
    std::cout << "Closest point: (" << closest.x << ", " << closest.y << ", " << closest.z << ")\n";
    return 0;
}
