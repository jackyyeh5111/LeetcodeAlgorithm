/*
    dfs/bfs
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> visited(graph.size(), 0);
        for (int u=0; u<graph.size(); ++u) {
            if (visited[u]==0&&!dfs(graph,visited,u,1)) return false;
        }
        return true;
    }

    // true if bipartite
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, int u, int group)
    {
        if (visited[u]!=0) return visited[u]==group;
        visited[u]=group;
        for (int v:graph[u]) {
            if (!dfs(graph,visited,v,3-group)) return false;
        }
        return true;
    }
};
