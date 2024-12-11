#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

// A structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;
    Edge(int dest, int wt) : destination(dest), weight(wt) {}
};

// A structure to represent a graph as an adjacency list
class Graph {
public:
    int num_vertices;  // Number of vertices
    vector<vector<Edge>> adj;  // Adjacency list

    Graph(int vertices) : num_vertices(vertices) {
        adj.resize(num_vertices);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight); // For undirected graph
    }

    // Heuristic function (Euclidean distance as an example)
    double heuristic(int u, int v, const vector<pair<int, int>>& coordinates) {
        int x1 = coordinates[u].first, y1 = coordinates[u].second;
        int x2 = coordinates[v].first, y2 = coordinates[v].second;
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    // A* algorithm to find the shortest path from start to goal
    void aStar(int start, int goal, const vector<pair<int, int>>& coordinates, vector<int>& shortest_dists) {
        // 1) Initialize distances and heuristic scores
        shortest_dists.resize(num_vertices, INT_MAX);
        shortest_dists[start] = 0;

        vector<int> prev(num_vertices, -1); // To reconstruct the path

        // Priority queue for (f_score, vertex), ordered by f_score
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> min_heap;
        min_heap.emplace(0.0, start);

        while (!min_heap.empty()) {
            int current = min_heap.top().second;
            min_heap.pop();

            // If we reach the goal, exit the loop
            if (current == goal) {
                break;
            }

            // Relaxation step
            for (const auto& [dest, weight] : adj[current]) {
                int tentative_g_score = shortest_dists[current] + weight;
                if (tentative_g_score < shortest_dists[dest]) {
                    shortest_dists[dest] = tentative_g_score;
                    prev[dest] = current;
                    double f_score = tentative_g_score + heuristic(dest, goal, coordinates);
                    min_heap.emplace(f_score, dest);
                }
            }
        }

        // Print the reconstructed path
        if (shortest_dists[goal] != INT_MAX) {
            vector<int> path;
            for (int at = goal; at != -1; at = prev[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            cout << "Shortest path: ";
            for (int v : path) {
                cout << v << " ";
            }
            cout << endl;
        } else {
            cout << "No path found." << endl;
        }
    }
};

int main() {
    Graph g(9);  // Create a graph with 9 vertices (0 to 8)

    // Add edges to the graph (undirected graph)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Coordinates of the vertices for heuristic calculation (e.g., 2D grid positions)
    vector<pair<int, int>> coordinates = {
        {0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8},
        {5, 10}, {6, 12}, {7, 14}, {8, 16}
    };

    int startVertex = 0;
    int goalVertex = 8;
    vector<int> shortestDistances;
    g.aStar(startVertex, goalVertex, coordinates, shortestDistances);

    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
