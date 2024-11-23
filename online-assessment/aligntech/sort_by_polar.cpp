#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // For atan2 and sqrt

struct Point {
    int x, y;
};

// Function to calculate the angle of the point with respect to the x-axis
double angle(const Point& p) {
    // remember!! y serves as "first" parameter
    return std::atan2(p.y, p.x);  // atan2 returns the angle between the x-axis and the line to (x, y)
}

// Function to calculate the distance of the point from the origin (0, 0)
double distance(const Point& p) {
    return std::sqrt(p.x * p.x + p.y * p.y);  // Euclidean distance
}

// Comparison function to sort points by angle and then by distance if angles are the same
bool comparePoints(const Point& p1, const Point& p2) {
    double angle1 = angle(p1);
    double angle2 = angle(p2);
    if (angle1 == angle2) {
        // If angles are the same, sort by distance
        return distance(p1) < distance(p2);
    }
    return angle1 < angle2;  // Sort by angle
}

int main() {
    std::vector<Point> points = {{1, 1}, {2, 2}, {1, -1}, {3, 0}, {0, 3}, {-1, -1}, {0, 0}};

    // Sort the points using the comparePoints function
    std::sort(points.begin(), points.end(), comparePoints);

    // Print the sorted points
    std::cout << "Sorted points:\n";
    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
