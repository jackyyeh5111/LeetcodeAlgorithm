class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size())
            return false;
        
        // init adj nodes
        vector<vector<int>> adj_nodes(n);
        initAdjNodes(adj_nodes, edges);

        // dfs
        vector<bool> visited(n, false);
        bool has_cycle = dfs(adj_nodes, visited, 0, -1); // TODO
        if (has_cycle)
            return false;

        // check if every node is visited
        for (bool visit : visited)
            if (!visit) return false;
        return true;
    }
    bool dfs(const vector<vector<int>> &adj_nodes, vector<bool> &visited, int cur_node, int parent_node) {
        if (visited[cur_node]) return true;
        visited[cur_node] = true;
        for (const auto & adj_node : adj_nodes[cur_node]) {
            if (adj_node == parent_node) continue;
            if (dfs(adj_nodes, visited, adj_node, cur_node))
                return true;
        }
        return false;
    }

    void initAdjNodes(vector<vector<int>> &adj_nodes, const vector<vector<int>>& edges) {
        for (const auto &edge : edges) {
            adj_nodes[edge[0]].push_back(edge[1]);
            adj_nodes[edge[1]].push_back(edge[0]);
        }
    }
};

/* 
    edges: [[0, 1], [0, 2]]
    =>
    adjacentcy_nodes:
        0: 1
        1: 0
        0: 2
        2: 0

    1. check # of edges == # of nodes - 1
    2. Make sure # of connected components == 1 (bfs)
    3. Check if every node is visited.
    
    Convert:
        1. Only one connected components
        2. Have no cycle

                       [6] (v)
                /              \
             [2] (v)    --       [8] (v)
 */

/* 
    Wrong answer!

    terminate called after throwing an instance of 'std::out_of_range'
        what():  _Map_base::at
 */
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        // init adj nodes
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        int count = 0;
        vector<int> visited(n);
        dfs(0, adj, count, visited);
        return count == n;
    }
    void dfs(int node, const unordered_map<int, vector<int>>& adj, int &count, vector<int> &visited) {
        if (visited[node])
            return;
        count++;
        visited[node] = true;
        for (int child : adj.at(node)) {
            if (!visited[child])
                dfs(child, adj, count, visited);
        }
    }
};

