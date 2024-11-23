#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

// A utility function to find the orientation of three points
// Returns:
// 0 -> p, q, r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;             // Collinear
    return (val > 0) ? 1 : 2;           // Clockwise or Counterclockwise
}

// Function to find the convex hull of a set of points
std::vector<Point> convexHull(std::vector<Point>& points) {
    // Find the bottom-most point (or left-most in case of a tie)
    Point start = *std::min_element(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return (p1.y < p2.y) || (p1.y == p2.y && p1.x < p2.x);
    });

    // Sort points based on polar angle with respect to the start point
    std::sort(points.begin(), points.end(), [&](const Point& p1, const Point& p2) {
        int orient = orientation(start, p1, p2);
        if (orient == 0) {
            // If collinear, sort by distance to start
            return (start.x - p1.x) * (start.x - p1.x) + (start.y - p1.y) * (start.y - p1.y) <
                   (start.x - p2.x) * (start.x - p2.x) + (start.y - p2.y) * (start.y - p2.y);
        }
        return orient == 2; // Counterclockwise comes first
    });

    // Initialize the hull with the first two points
    std::vector<Point> hull;
    for (const auto& point : points) {
        while (hull.size() >=2 && orientation(hull[hull.size() - 2], hull.back(), point) != 2) {
            hull.pop_back(); // Remove the last point if it does not form a left turn
        }
        hull.push_back(point);
    }

    return hull;
}

// Helper function to print the convex hull points
void printHull(const std::vector<Point>& hull) {
    for (const auto& point : hull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }
}

int main() {
    std::vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    std::vector<Point> hull = convexHull(points);

    std::cout << "The points in the convex hull are:\n";
    printHull(hull);

    return 0;
}
