#include <iostream>
#include <vector>

struct Point {
    float x, y, z;
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
};

class Octree {
public:
    struct Node {
        Point* point = nullptr;
        Node* children[8] = {nullptr};

        Node() {}
    };

private:
    Node* root;
    float minX, minY, minZ, maxX, maxY, maxZ; // The bounding box for the octree

    // Helper function to compute the index for the child node
    int getChildIndex(const Point& p, const float midX, const float midY, const float midZ) {
        int index = 0;
        if (p.x >= midX) index |= 1;
        if (p.y >= midY) index |= 2;
        if (p.z >= midZ) index |= 4;
        return index;
    }

    // Recursive function to insert a point into the octree
    void insert(Node* node, const Point& p, const float minX, const float minY, const float minZ, const float maxX, const float maxY, const float maxZ) {
        if (node->point == nullptr) {
            node->point = new Point(p.x, p.y, p.z);
            return;
        }

        float midX = (minX + maxX) / 2;
        float midY = (minY + maxY) / 2;
        float midZ = (minZ + maxZ) / 2;

        int childIndex = getChildIndex(p, midX, midY, midZ);
        
        if (node->children[childIndex] == nullptr) {
            node->children[childIndex] = new Node();
        }

        insert(node->children[childIndex], p, (childIndex & 1) ? midX : minX, (childIndex & 2) ? midY : minY, (childIndex & 4) ? midZ : minZ, 
               (childIndex & 1) ? maxX : midX, (childIndex & 2) ? maxY : midY, (childIndex & 4) ? maxZ : midZ);
    }

    // Helper function to traverse and print the tree
    void traverse(Node* node) {
        if (node == nullptr) return;
        if (node->point != nullptr) {
            std::cout << "Point: (" << node->point->x << ", " << node->point->y << ", " << node->point->z << ")\n";
        }

        for (int i = 0; i < 8; ++i) {
            traverse(node->children[i]);
        }
    }

public:
    // Constructor to initialize the octree with the bounding box
    Octree(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) :
        minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {
        root = new Node();
    }

    // Function to insert a point into the octree
    void insert(const Point& p) {
        insert(root, p, minX, minY, minZ, maxX, maxY, maxZ);
    }

    // Function to print all points in the octree
    void print() {
        traverse(root);
    }
};

// Main function to test the octree implementation
int main() {
    // Create an octree with a bounding box from (0, 0, 0) to (10, 10, 10)
    Octree octree(0, 0, 0, 10, 10, 10);

    // Insert some points into the octree
    octree.insert(Point(1, 1, 1));
    octree.insert(Point(2, 2, 2));
    octree.insert(Point(3, 3, 3));
    octree.insert(Point(5, 5, 5));

    // Print the points stored in the octree
    std::cout << "Points in Octree:\n";
    octree.print();

    return 0;
}
