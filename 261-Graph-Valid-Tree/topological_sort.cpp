class Solution2 {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return true;
        if (edges.size() != n - 1)
            return false;
        
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegrees;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            ++indegrees[edge[0]];
            ++indegrees[edge[1]];
        }

        queue<int> que;
        for (auto indeg : indegrees) {
            if (indeg.second == 0) return false;
            if (indeg.second == 1)
                que.push(indeg.first);
        }

        // topological sort
        int num_visit = 0;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            --indegrees[node]; // Ensure never being visited again.
            ++num_visit;
            for (auto adj_node : adj[node]) {
                if (--indegrees[adj_node] == 1)
                    que.push(adj_node);
            }
        }
        return num_visit == n;
    }
};

/* 
    Wrong answer!

    沒有考慮到 unconnected graph. 
    For example:
        - n = 4
        - edges = [[0,1],[2,3]]
 
    也沒考慮到單節點 tree
 */
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        // init adj nodes
        unordered_set<int> connected;
        for (auto edge : edges) {
            connected.insert(edge[0]);
            connected.insert(edge[1]);
        }
        return connected.size() == n;
    }
};

/* 
    Wrong answer!

    沒有考慮到 unconnected graph. 
    For example:
        - n = 4
        - edges = [[0,1],[2,3]]
 
    也沒考慮到單節點 tree
 */
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegrees;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            ++indegrees[edge[0]];
            ++indegrees[edge[1]];
        }

        queue<int> que;
        for (auto indeg : indegrees) {
            if (indeg.second == 0) return false;
            if (indeg.second == 1)
                que.push(indeg.first);
        }

        // topological sort
        int num_visit = 0;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            --indegrees[node]; // Ensure never being visited again.
            ++num_visit;
            for (auto adj_node : adj[node]) {
                if (--indegrees[adj_node] == 1)
                    que.push(adj_node);
            }
        }
        return num_visit == n;
    }
};










