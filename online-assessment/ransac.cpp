#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>

// Define a Point struct to represent each 2D point
struct Point {
    double x, y;
};

// Function to compute the line parameters (slope m, intercept b) from two points
void fitLine(const Point& p1, const Point& p2, double& m, double& b) {
    m = (p2.y - p1.y) / (p2.x - p1.x);  // Slope
    b = p1.y - m * p1.x;  // Intercept
}

// Function to calculate the distance from a point to a line
/* 
    L: y = mx + b = 0
 */
double pointToLineDistance(const Point& p, double m, double b) {
    return std::abs(m * p.x - p.y + b) / std::sqrt(m * m + 1);
}

// RANSAC line fitting function
void ransacLineFitting(const std::vector<Point>& points, int iterations, double threshold, double& m, double& b) {
    srand(time(0));
    int maxInliers = 0;
    
    // Iterate for the specified number of iterations
    for (int i = 0; i < iterations; i++) {
        // Randomly select two points
        int idx1 = rand() % points.size();
        int idx2 = rand() % points.size();
        while (idx2 == idx1) idx2 = rand() % points.size();  // Ensure two distinct points

        Point p1 = points[idx1];
        Point p2 = points[idx2];

        // Fit a line using the selected points
        double m_candidate, b_candidate;
        fitLine(p1, p2, m_candidate, b_candidate);
        std::cout << "m_candidate: " << m_candidate << " | b_candidate: " << b_candidate << '\n';

        // Count inliers
        int inliers = 0;
        for (const auto& point : points) {
            if (pointToLineDistance(point, m_candidate, b_candidate) < threshold) {
                inliers++;
            }
        }

        // Update the best line if more inliers are found
        if (inliers > maxInliers) {
            maxInliers = inliers;
            m = m_candidate;
            b = b_candidate;
        }
    }
}

int main() {
    // Example points
    std::vector<Point> points = {{1, 2}, {2, 3.9}, {3, 6}, {4, 7.8}, {5, 10}, {6, 12}};
    
    // Parameters for RANSAC
    int iterations = 1000;
    double threshold = 0.5; // Distance threshold for inliers
    
    // Variables to hold the line parameters
    double m = 0, b = 0;
    
    // Run RANSAC
    ransacLineFitting(points, iterations, threshold, m, b);
    
    // Output the result
    std::cout << "Best fit line: y = " << m << "x + " << b << std::endl;

    return 0;
}
