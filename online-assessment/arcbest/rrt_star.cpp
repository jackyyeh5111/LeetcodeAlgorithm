#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <memory>
#include <algorithm>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Node {
    Point point;
    std::shared_ptr<Node> parent;
    double cost; // add cost here

    Node(Point p, std::shared_ptr<Node> parent = nullptr, double cost = 0) 
        : point(p), parent(parent), cost(cost) {}
};

double distance(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

Point randomPoint(double width, double height) {
    return Point((double)rand() / RAND_MAX * width, (double)rand() / RAND_MAX * height);
}

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

void rewire(std::vector<std::shared_ptr<Node>>& tree, std::shared_ptr<Node> newNode, double maxStep) {
    // Check all nodes in the tree for possible re-parenting.
    for (auto& node : tree) {
        if (node != newNode) {
            double dist = distance(node->point, newNode->point);
            double newCost = newNode->cost + dist;

            if (newCost < node->cost && isCollisionFree(newNode->point, node->point)) {
                node->parent = newNode;
                node->cost = newCost;
            }
        }
    }
}

std::vector<Point> rrtStar(const Point& start, const Point& goal, double width, double height, double maxStep, int maxIterations) {
    std::vector<std::shared_ptr<Node>> tree;
    tree.push_back(std::make_shared<Node>(start));

    for (int i = 0; i < maxIterations; ++i) {
        Point randPoint = randomPoint(width, height);
        auto nearest = nearestNode(tree, randPoint);
        Point newPoint = steer(nearest->point, randPoint, maxStep);

        if (isCollisionFree(nearest->point, newPoint)) {
            // Create the new node
            auto newNode = std::make_shared<Node>(newPoint, nearest, nearest->cost + distance(nearest->point, newPoint));
            tree.push_back(newNode);

            // Rewire the tree to optimize path
            rewire(tree, newNode, maxStep);

            // Check if goal is reached
            if (distance(newPoint, goal) <= maxStep) {
                if (isCollisionFree(newPoint, goal)) {
                    auto goalNode = std::make_shared<Node>(goal, newNode, newNode->cost + distance(newPoint, goal));
                    return extractPath(goalNode);
                }
            }
        }
    }

    return {}; // Return empty path if no solution is found
}

int main() {
    srand(time(nullptr));

    Point start(0, 0);
    Point goal(9, 9);
    double width = 10.0;
    double height = 10.0;
    double maxStep = 1.0;
    int maxIterations = 1000;

    std::vector<Point> path = rrtStar(start, goal, width, height, maxStep, maxIterations);

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
