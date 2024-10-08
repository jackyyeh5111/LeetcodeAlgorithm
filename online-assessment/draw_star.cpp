#include <iostream>
#include <cmath>
#include <vector>

// Point structure to hold x and y coordinates
struct Point {
    double x, y;
};

// Function to generate the points of the star
std::vector<Point> generateStarPoints(int N, double radius, double x_center, double y_center) {
    std::vector<Point> points;

    // Step size to connect alternating points
    int step = 2; // You can adjust this if needed

    // Generate N points on the circle
    for (int i = 0; i < N; ++i) {
        double angle = 2 * M_PI * i / N;
        double x = x_center + radius * cos(angle);
        double y = y_center + radius * sin(angle);
        points.push_back({x, y});
    }

    // Return the generated points
    return points;
}

// Function to print the star points
void printStarPoints(const std::vector<Point>& points, int step) {
    int N = points.size();

    std::cout << "Star edges (from one point to another):" << std::endl;
    for (int i = 0; i < N; ++i) {
        int next = (i + step) % N; // Connect to the next point based on the step
        std::cout << "Line from (" << points[i].x << ", " << points[i].y << ") to ("
                  << points[next].x << ", " << points[next].y << ")" << std::endl;
    }
}

int main() {
    int N; // Number of points on the star
    double radius; // Radius of the circle
    double x_center, y_center; // Center of the circle

    // Input: center, radius, and number of points
    std::cout << "Enter number of points for the star (N): ";
    std::cin >> N;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    std::cout << "Enter the x and y coordinates of the center: ";
    std::cin >> x_center >> y_center;

    // Generate points of the star
    std::vector<Point> starPoints = generateStarPoints(N, radius, x_center, y_center);

    // Choose a step (for example, connect every second point)
    int step = 2;
    
    // Print the star points (or you can implement a drawing mechanism)
    printStarPoints(starPoints, step);

    return 0;
}
