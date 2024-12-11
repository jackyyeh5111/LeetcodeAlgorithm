#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Node {
    Point point;
    Node* parent;
    Node(Point p, Node* parent = nullptr) : point(p), parent(parent) {}
};

double distance(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

Point randomPoint(double width, double height) {
    return Point((double)rand() / RAND_MAX * width, (double)rand() / RAND_MAX * height);
}

Node* nearestNode(const std::vector<Node*>& tree, const Point& point) {
    Node* nearest = nullptr;
    double minDist = std::numeric_limits<double>::max();

    for (Node* node : tree) {
        double dist = distance(node->point, point);
        if (dist < minDist) {
            minDist = dist;
            nearest = node;
        }
    }

    return nearest;
}

Point steer(const Point& from, const Point& to, double maxStep) {
    double dist = distance(from, to);
    if (dist <= maxStep) return to;
    double theta = std::atan2(to.y - from.y, to.x - from.x);
    return Point(from.x + maxStep * std::cos(theta), from.y + maxStep * std::sin(theta));
}

bool isCollisionFree(const Point& start, const Point& end) {
    // For simplicity, assume the space is empty.
    // Add obstacle collision logic here.
    return true;
}

std::vector<Point> extractPath(Node* goalNode) {
    std::vector<Point> path;
    Node* current = goalNode;
    while (current) {
        path.push_back(current->point);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Point> rrt(const Point& start, const Point& goal, double width, double height, double maxStep, int maxIterations) {
    std::vector<Node*> tree;
    tree.push_back(new Node(start));

    for (int i = 0; i < maxIterations; ++i) {
        Point randPoint = randomPoint(width, height);
        Node* nearest = nearestNode(tree, randPoint);
        Point newPoint = steer(nearest->point, randPoint, maxStep);

        if (isCollisionFree(nearest->point, newPoint)) {
            Node* newNode = new Node(newPoint, nearest);
            tree.push_back(newNode);

            if (distance(newPoint, goal) <= maxStep) {
                if (isCollisionFree(newPoint, goal)) {
                    Node* goalNode = new Node(goal, newNode);
                    std::vector<Point> path = extractPath(goalNode);

                    // Clean up allocated nodes
                    for (Node* node : tree) delete node;

                    return path;
                }
            }
        }
    }

    // If no path is found, clean up and return empty path
    for (Node* node : tree) delete node;
    return {};
}

int main() {
    srand(time(nullptr));

    Point start(0, 0);
    Point goal(9, 9);
    double width = 10.0;
    double height = 10.0;
    double maxStep = 1.0;
    int maxIterations = 1000;

    std::vector<Point> path = rrt(start, goal, width, height, maxStep, maxIterations);

    if (!path.empty()) {
        std::cout << "Path found:\n";
        for (const Point& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ")\n";
        }
    } else {
        std::cout << "No path found." << std::endl;
    }

    return 0;
}


/* 
    Shared ptr version
 */

#include <memory> // For std::shared_ptr

struct Node {
    Point point;
    std::shared_ptr<Node> parent; // Use shared_ptr instead of raw pointer
    Node(Point p, std::shared_ptr<Node> parent = nullptr) : point(p), parent(parent) {}
};

std::shared_ptr<Node> nearestNode(const std::vector<std::shared_ptr<Node>>& tree, const Point& point) {
    std::shared_ptr<Node> nearest = nullptr;
    double minDist = std::numeric_limits<double>::max();

    for (const auto& node : tree) {
        double dist = distance(node->point, point);
        if (dist < minDist) {
            minDist = dist;
            nearest = node;
        }
    }

    return nearest;
}

std::vector<Point> extractPath(std::shared_ptr<Node> goalNode) {
    std::vector<Point> path;
    auto current = goalNode;
    while (current) {
        path.push_back(current->point);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Point> rrt(const Point& start, const Point& goal, double width, double height, double maxStep, int maxIterations) {
    std::vector<std::shared_ptr<Node>> tree;
    tree.push_back(std::make_shared<Node>(start));

    for (int i = 0; i < maxIterations; ++i) {
        Point randPoint = randomPoint(width, height);
        auto nearest = nearestNode(tree, randPoint);
        Point newPoint = steer(nearest->point, randPoint, maxStep);

        if (isCollisionFree(nearest->point, newPoint)) {
            auto newNode = std::make_shared<Node>(newPoint, nearest);
            tree.push_back(newNode);

            if (distance(newPoint, goal) <= maxStep) {
                if (isCollisionFree(newPoint, goal)) {
                    auto goalNode = std::make_shared<Node>(goal, newNode);
                    return extractPath(goalNode);
                }
            }
        }
    }

    return {}; // Return empty path if no solution is found
}
