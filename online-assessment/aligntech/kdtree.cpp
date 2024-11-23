#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

struct Point {
    std::vector<double> coordinates;

    Point(std::initializer_list<double> list) : coordinates(list) {}

    double operator[](size_t idx) const {
        return coordinates[idx];
    }

    size_t dimensions() const {
        return coordinates.size();
    }
};

struct KDNode {
    Point point;
    KDNode* left;
    KDNode* right;

    KDNode(const Point& pt) : point(pt), left(nullptr), right(nullptr) {}
};

// Function to calculate Euclidean distance
double euclideanDistance(const Point& p1, const Point& p2) {
    double sum = 0;
    for (size_t i = 0; i < p1.dimensions(); ++i) {
        sum += std::pow(p1[i] - p2[i], 2);
    }
    return std::sqrt(sum);
}

// Function to build the KD-Tree recursively
KDNode* buildKDTree(std::vector<Point>& points, size_t depth = 0) {
    if (points.empty()) return nullptr;

    // Select axis based on depth (cyclic)
    size_t axis = depth % points[0].dimensions();

    // Sort points based on the axis and find the median
    std::sort(points.begin(), points.end(), [&axis](const Point& p1, const Point& p2) {
        return p1[axis] < p2[axis];
    });

    size_t medianIdx = points.size() / 2;
    KDNode* node = new KDNode(points[medianIdx]);

    // Recursively build the left and right subtrees
    std::vector<Point> leftPoints(points.begin(), points.begin() + medianIdx);
    std::vector<Point> rightPoints(points.begin() + medianIdx + 1, points.end());

    node->left = buildKDTree(leftPoints, depth + 1);
    node->right = buildKDTree(rightPoints, depth + 1);

    return node;
}

// Function to find the nearest neighbor recursively
void nearestNeighbor(KDNode* root, const Point& target, size_t depth, KDNode*& bestNode, double& bestDist) {
    if (root == nullptr) return;

    double dist = euclideanDistance(root->point, target);
    if (dist < bestDist) {
        bestDist = dist;
        bestNode = root;
    }

    size_t axis = depth % target.dimensions();
    KDNode* nextBranch = nullptr;
    KDNode* oppositeBranch = nullptr;

    // Recursively search the left or right subtree based on the axis and target
    if (target[axis] < root->point[axis]) {
        nextBranch = root->left;
        oppositeBranch = root->right;
    } else {
        nextBranch = root->right;
        oppositeBranch = root->left;
    }

    nearestNeighbor(nextBranch, target, depth + 1, bestNode, bestDist);

    // Check if we need to search the opposite branch
    if (std::abs(target[axis] - root->point[axis]) < bestDist) {
        nearestNeighbor(oppositeBranch, target, depth + 1, bestNode, bestDist);
    }
}

int main() {
    // Example points (3D points)
    std::vector<Point> points = {
        Point{2.0, 3.0, 4.0},
        Point{5.0, 4.0, 3.0},
        Point{9.0, 6.0, 1.0},
        Point{4.0, 7.0, 2.0},
        Point{8.0, 1.0, 5.0}
    };

    // Build the KD-Tree
    KDNode* root = buildKDTree(points);

    // Query point
    Point queryPoint{7.0, 3.0, 2.0};

    // Nearest neighbor search
    KDNode* bestNode = nullptr;
    double bestDist = std::numeric_limits<double>::infinity();
    nearestNeighbor(root, queryPoint, 0, bestNode, bestDist);

    // Output the result
    std::cout << "Nearest neighbor: (";
    for (size_t i = 0; i < bestNode->point.dimensions(); ++i) {
        std::cout << bestNode->point[i] << (i < bestNode->point.dimensions() - 1 ? ", " : "");
    }
    std::cout << ") with distance: " << bestDist << std::endl;

    return 0;
}
