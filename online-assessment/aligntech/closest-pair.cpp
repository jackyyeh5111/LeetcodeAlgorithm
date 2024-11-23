#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>

struct Point {
    double x, y;
};

// Utility function to calculate the distance between two points
double distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A brute force approach to find the closest distance in a small subset of points
double bruteForce(const std::vector<Point>& points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minDist = std::min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

// Function to find the smallest distance across the boundary strip
double closestStrip(const std::vector<Point>& strip, double d) {
    double minDist = d;

    // Sort strip by y-coordinate (already sorted in the main algorithm)
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = std::min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Divide and conquer function to find the closest distance
double closestUtil(std::vector<Point>& points, int left, int right) {
    // If the number of points is small, use brute force
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    // Find the middle point
    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    // Recursively find the smallest distance in left and right halves
    double leftMinDist = closestUtil(points, left, mid);
    double rightMinDist = closestUtil(points, mid, right);

    // Find the smaller of the two distances
    double d = std::min(leftMinDist, rightMinDist);

    // Collect points in the strip around the middle
    std::vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (std::abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    // Find the smallest distance in the strip
    return std::min(d, closestStrip(strip, d));
}

// Main function to find the closest pair of points
double closestPair(std::vector<Point>& points) {
    // Sort the points by x-coordinate
    std::sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
    });

    return closestUtil(points, 0, points.size());
}

int main() {
    // Example set of points
    std::vector<Point> points = {
        {2.0, 3.0}, {12.0, 30.0}, {40.0, 50.0}, {5.0, 1.0},
        {12.0, 10.0}, {3.0, 4.0}
    };

    // Find and print the smallest distance
    double minDistance = closestPair(points);
    std::cout << "The smallest distance is: " << minDistance << std::endl;

    return 0;
}
