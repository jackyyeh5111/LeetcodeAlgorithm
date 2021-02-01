/*
    0 - 1 - 2 - 3
        |_______|
*/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.size()!=n-1) return false;
        vector<vector<int>> graph(n,vector<int>{});
        vector<bool> visited(n,0);
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        if (dfs(graph,visited,0,-1)) return false;
        for (bool v:visited) {
            if (!v) return false;
        }
        return true;
    }

    // true if cyclic
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int u, int w)
    {
        if (visited[u]) return true;
        visited[u]=true;
        for (int v:graph[u]) {
            if (v!=w&&dfs(graph,visited,v,u))
                return true;
        }
        return false;
    }
};
