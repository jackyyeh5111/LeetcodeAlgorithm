#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Struct to represent a 2D point
struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

// Function to compute the area of a polygon using the Shoelace Algorithm
double computePolygonArea(const vector<Point>& vertices) {
    int n = vertices.size();
    if (n < 3) {
        throw invalid_argument("A polygon must have at least 3 vertices.");
    }

    double area = 0.0;

    // Apply the Shoelace formula
    for (int i = 0; i < n; ++i) {
        const Point& current = vertices[i];
        const Point& next = vertices[(i + 1) % n]; // Next vertex (wrap around using modulo)
        area += (current.x * next.y - current.y * next.x);
    }

    return fabs(area) / 2.0; // Take the absolute value and divide by 2
}

int main() {
    // Example: Define the vertices of a polygon (counter-clockwise)
    vector<Point> polygon = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 3.0},
        {0.0, 3.0}
    };

    try {
        // Compute the area
        double area = computePolygonArea(polygon);
        cout << "Area of the polygon: " << area << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
