class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adjs;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // create bidirectional graph using adjcency matrix
        for (int i = 0; i < equations.size(); i++) {
            string node0 = equations[i][0];
            string node1 = equations[i][1];
            adjs[node0].push_back({node1, values[i]});
            adjs[node1].push_back({node0, 1.0 / values[i]});
        }

        vector<double> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            string node0 = queries[i][0];
            string node1 = queries[i][1];
            if (adjs.count(node0) == 0 || adjs.count(node1) == 0)
                continue;
            
            unordered_set<string> visited;
            double val = 1.0;
            if (dfs(node0, node1, val, visited))
                ans[i] = val;
        }
        return ans;
    }
    bool dfs(string node, string target_node, double &val, unordered_set<string> &visited) {
        if (node == target_node) return true; 
        if (visited.count(node)) return false;
        
        visited.insert(node);
        /* 
            0 -> 1 -> 2 -> 3
              1    10   20           
         */
        for (const auto &next_pair : adjs[node]) {
            if (dfs(next_pair.first, target_node, val, visited)) {
                val *= next_pair.second;
                return true;
            }
        }
        return false;
    }
};

/* 
    1) Create a directed graph and store their parents node(for checking the set root)
    2) Check Two nodes for each query if they are in same disjoint set,
        if yes: DFS
        if no: return -1

    required variables:
        1. adjcency matrix
        2. parents vector

    a / b => 2
    b / c => 3
    b / d => 1
    e / f => 2

         d
         ^ 
    a -> b -> c
       2.   3
    
    e -> f
       2 

    b / a = 1/2
 */