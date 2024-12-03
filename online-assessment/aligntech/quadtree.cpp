#include <iostream>
#include <vector>
#include <memory>

struct Point {
    double x, y;

    Point(double x_, double y_) : x(x_), y(y_) {}
};

struct BoundingBox {
    double x_min, x_max, y_min, y_max;

    BoundingBox(double x_min_, double x_max_, double y_min_, double y_max_)
        : x_min(x_min_), x_max(x_max_), y_min(y_min_), y_max(y_max_) {}

    // Check if a point is within this bounding box
    bool contains(const Point& p) const {
        return (p.x >= x_min && p.x <= x_max && p.y >= y_min && p.y <= y_max);
    }

    // Check if this bounding box intersects another
    bool intersects(const BoundingBox& other) const {
        return !(x_min > other.x_max || x_max < other.x_min || 
                 y_min > other.y_max || y_max < other.y_min);
    }
};

class Quadtree {
    BoundingBox boundary;
    int capacity; // Maximum points before subdivision
    std::vector<Point> points;
    bool divided;

    std::unique_ptr<Quadtree> northeast;
    std::unique_ptr<Quadtree> northwest;
    std::unique_ptr<Quadtree> southeast;
    std::unique_ptr<Quadtree> southwest;

public:
    Quadtree(const BoundingBox& boundary_, int capacity_)
        : boundary(boundary_), capacity(capacity_), divided(false) {}

    // Insert a point into the quadtree
    bool insert(const Point& p) {
        if (!boundary.contains(p)) {
            return false; // Point is out of bounds
        }

        if (points.size() < capacity) {
            points.push_back(p);
            return true;
        }

        if (!divided) {
            subdivide();
        }

        return (northeast->insert(p) || northwest->insert(p) ||
                southeast->insert(p) || southwest->insert(p));
    }

    // Query points within a range
    void query(const BoundingBox& range, std::vector<Point>& found) const {
        if (!boundary.intersects(range)) {
            return; // No intersection
        }

        for (const auto& p : points) {
            if (range.contains(p)) {
                found.push_back(p);
            }
        }

        if (divided) {
            northeast->query(range, found);
            northwest->query(range, found);
            southeast->query(range, found);
            southwest->query(range, found);
        }
    }

private:
    // Subdivide this quadtree into four quadrants
    void subdivide() {
        double x_mid = (boundary.x_min + boundary.x_max) / 2.0;
        double y_mid = (boundary.y_min + boundary.y_max) / 2.0;

        northeast = std::make_unique<Quadtree>(
            BoundingBox(x_mid, boundary.x_max, boundary.y_min, y_mid), capacity);
        northwest = std::make_unique<Quadtree>(
            BoundingBox(boundary.x_min, x_mid, boundary.y_min, y_mid), capacity);
        southeast = std::make_unique<Quadtree>(
            BoundingBox(x_mid, boundary.x_max, y_mid, boundary.y_max), capacity);
        southwest = std::make_unique<Quadtree>(
            BoundingBox(boundary.x_min, x_mid, y_mid, boundary.y_max), capacity);

        divided = true;
    }
};

// Example usage
int main() {
    BoundingBox boundary(0, 10, 0, 10);
    Quadtree qt(boundary, 4);

    // Insert points into the quadtree
    qt.insert(Point(2, 3));
    qt.insert(Point(5, 5));
    qt.insert(Point(9, 6));
    qt.insert(Point(4, 8));
    qt.insert(Point(7, 1));

    // Query a range
    BoundingBox range(3, 7, 2, 10);
    std::vector<Point> found;
    qt.query(range, found);

    // Print results
    std::cout << "Points in range: ";
    for (const auto& p : found) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}
