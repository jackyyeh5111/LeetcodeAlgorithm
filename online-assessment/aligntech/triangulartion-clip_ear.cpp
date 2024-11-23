#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

struct Point {
    double x, y;
};

// Utility function to calculate the signed area of a triangle
double signedArea(const Point& p1, const Point& p2, const Point& p3) {
    return 0.5 * ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

// Check if a point is inside a triangle
bool isPointInTriangle(const Point& p, const Point& a, const Point& b, const Point& c) {
    double totalArea = std::abs(signedArea(a, b, c));
    double area1 = std::abs(signedArea(p, b, c));
    double area2 = std::abs(signedArea(a, p, c));
    double area3 = std::abs(signedArea(a, b, p));
    return std::abs(totalArea - (area1 + area2 + area3)) < 1e-9;
}

// Check if a triangle formed by vertices i, j, k is an "ear"
bool isEar(const std::vector<Point>& polygon, int i, int j, int k) {
    Point a = polygon[i];
    Point b = polygon[j];
    Point c = polygon[k];

    // Check if the triangle is convex
    if (signedArea(a, b, c) <= 0) return false;

    // Check if no other points are inside the triangle
    for (size_t m = 0; m < polygon.size(); ++m) {
        if (m != i && m != j && m != k && isPointInTriangle(polygon[m], a, b, c)) {
            return false;
        }
    }
    return true;
}

// Perform ear-clipping triangulation
void earClippingTriangulation(std::vector<Point> polygon, std::vector<std::vector<Point>>& triangles) {
    int n = polygon.size();
    if (n < 3) return;

    // Use indices to track remaining vertices
    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    while (indices.size() > 3) {
        bool earFound = false;
        for (size_t j = 0; j < indices.size(); ++j) {
            int i = indices[(j - 1 + indices.size()) % indices.size()];
            int k = indices[(j + 1) % indices.size()];
            int current = indices[j];

            // Check if this is an ear
            if (isEar(polygon, i, current, k)) {
                // Add the ear triangle to the result
                triangles.push_back({polygon[i], polygon[current], polygon[k]});

                // Remove the current vertex from the polygon
                indices.erase(indices.begin() + j);
                earFound = true;
                break;
            }
        }
        if (!earFound) {
            std::cerr << "Failed to find an ear. The polygon might be invalid.\n";
            return;
        }
    }

    // Add the final triangle
    triangles.push_back({polygon[indices[0]], polygon[indices[1]], polygon[indices[2]]});
}

int main() {
    // Define an example concave polygon
    std::vector<Point> polygon = {
        {0, 0}, {4, 0}, {4, 4}, {2, 2}, {0, 4}  // Concave polygon
    };

    // Store the resulting triangles
    std::vector<std::vector<Point>> triangles;

    // Perform triangulation
    earClippingTriangulation(polygon, triangles);

    // Print the resulting triangles
    std::cout << "Triangles formed by ear-clipping:\n";
    for (const auto& triangle : triangles) {
        for (const auto& vertex : triangle) {
            std::cout << "(" << vertex.x << ", " << vertex.y << ") ";
        }
        std::cout << "\n";
    }

    return 0;
}
