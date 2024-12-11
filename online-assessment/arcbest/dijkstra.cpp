#include <iostream>
#include <vector>
#include <queue>
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

    // Dijkstra's algorithm to find the shortest path from source to all vertices
    void dijkstra(int start, vector<int> &shortest_dists) {
        // 1) init distance
        shortest_dists.resize(num_vertices, INT_MAX);
        shortest_dists[start] = 0;
        
        // 2) init min_heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.emplace(0, start);

        // 3) check min_heap until it is empty
        while(!min_heap.empty()) {
            int node = min_heap.top().second;
            min_heap.pop();
            
            // Relaxation step: if a shorter path is found
            for (const auto& [dest, weight] : adj[node]) {
                if (shortest_dists[node] + weight < shortest_dists[dest]) {
                    shortest_dists[dest] = shortest_dists[node] + weight;
                    min_heap.emplace(shortest_dists[dest], dest);
                }
            }
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

    int startVertex = 0;
    vector<int> shortestDistances;
    g.dijkstra(startVertex, shortestDistances);

    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
