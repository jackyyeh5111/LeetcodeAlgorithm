#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

// Define a structure for 3D points/vertices
struct Vertex {
    float x, y, z;

    Vertex(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Calculate the distance between two vertices
    float distanceTo(const Vertex& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }

    // Calculate the centroid of a set of vertices (average position)
    static Vertex centroid(const vector<Vertex>& vertices) {
        float sumX = 0, sumY = 0, sumZ = 0;
        for (const auto& v : vertices) {
            sumX += v.x;
            sumY += v.y;
            sumZ += v.z;
        }
        return Vertex(sumX / vertices.size(), sumY / vertices.size(), sumZ / vertices.size());
    }
};

// Define a structure for a triangle in the mesh
struct Triangle {
    int v1, v2, v3;  // Indices of the vertices forming the triangle

    Triangle(int v1, int v2, int v3) : v1(v1), v2(v2), v3(v3) {}
};

// Mesh simplification class using vertex clustering
class MeshSimplifier {
public:
    vector<Vertex> vertices;
    vector<Triangle> triangles;
    float cellSize;  // Size of each grid cell for clustering

    // Constructor with a specified grid cell size
    MeshSimplifier(float cellSize) : cellSize(cellSize) {}

    // Add a vertex to the mesh
    void addVertex(const Vertex& v) {
        vertices.push_back(v);
    }

    // Add a triangle to the mesh
    void addTriangle(int v1, int v2, int v3) {
        triangles.push_back(Triangle(v1, v2, v3));
    }

    // Simplify the mesh using vertex clustering
    void simplify() {
        // Step 1: Create a grid and cluster vertices into the grid
        unordered_map<int, vector<Vertex>> grid;

        for (const auto& v : vertices) {
            // Determine the grid cell index for the vertex
            int gridX = static_cast<int>(floor(v.x / cellSize));
            int gridY = static_cast<int>(floor(v.y / cellSize));
            int gridZ = static_cast<int>(floor(v.z / cellSize));

            // Combine the indices to form a unique key for the grid cell
            int key = (gridX << 20) + (gridY << 10) + gridZ;

            // Add the vertex to the corresponding grid cell
            grid[key].push_back(v);
        }

        // Step 2: Calculate the centroid for each grid cell and replace vertices
        vector<Vertex> newVertices;
        unordered_map<int, int> oldToNewVertexMap;

        for (auto& entry : grid) {
            // Calculate the centroid of all vertices in the grid cell
            Vertex centroid = Vertex::centroid(entry.second);

            // Add the centroid as a new vertex
            newVertices.push_back(centroid);

            // Map each old vertex to the new vertex index
            for (const auto& v : entry.second) {
                int oldIndex = find(vertices.begin(), vertices.end(), v) - vertices.begin();
                oldToNewVertexMap[oldIndex] = newVertices.size() - 1;
            }
        }

        // Step 3: Rebuild the mesh with the new vertices
        vector<Triangle> newTriangles;
        for (const auto& t : triangles) {
            int newV1 = oldToNewVertexMap[t.v1];
            int newV2 = oldToNewVertexMap[t.v2];
            int newV3 = oldToNewVertexMap[t.v3];

            // Add the new triangle formed by the new vertex indices
            newTriangles.push_back(Triangle(newV1, newV2, newV3));
        }

        // Replace the old vertices and triangles with the new ones
        vertices = newVertices;
        triangles = newTriangles;
    }

    // Print the mesh (vertices and triangles)
    void printMesh() {
        cout << "Vertices: " << endl;
        for (const auto& v : vertices) {
            cout << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
        }

        cout << "Triangles: " << endl;
        for (const auto& t : triangles) {
            cout << t.v1 << " " << t.v2 << " " << t.v3 << endl;
        }
    }
};

int main() {
    // Create a mesh simplifier with a grid cell size of 1.0
    MeshSimplifier mesh(1.0);

    // Add vertices to the mesh
    mesh.addVertex(Vertex(0.0, 0.0, 0.0));
    mesh.addVertex(Vertex(1.0, 0.0, 0.0));
    mesh.addVertex(Vertex(0.0, 1.0, 0.0));
    mesh.addVertex(Vertex(1.0, 1.0, 0.0));
    mesh.addVertex(Vertex(0.5, 0.5, 1.0));

    // Add triangles to the mesh
    mesh.addTriangle(0, 1, 2);
    mesh.addTriangle(1, 2, 3);
    mesh.addTriangle(2, 3, 4);

    // Print the original mesh
    cout << "Original Mesh: " << endl;
    mesh.printMesh();

    // Simplify the mesh using vertex clustering
    mesh.simplify();

    // Print the simplified mesh
    cout << "\nSimplified Mesh: " << endl;
    mesh.printMesh();

    return 0;
}
