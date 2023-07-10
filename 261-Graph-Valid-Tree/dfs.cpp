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
        count++; // remember to add one to count first before return.
        if (adj.find(0) == adj.end()) // add this line.
            return;
        visited[node] = true;
        for (int child : adj.at(node)) {
            if (!visited[child])
                dfs(child, adj, count, visited);
        }
    }
};


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

