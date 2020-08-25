// T:O(V+E), S:O(V+E)
class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> paths;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        /*
            use dfs & backtracking to save path
        */
        visited = vector<bool>(graph.size(),false);
        vector<int> path;
        help(graph, 0, graph.size()-1, path);
        return paths;
    }

    void help(vector<vector<int>> &graph, int u, int target, vector<int> &path)
    {
        if (visited[u]) return;
        visited[u]=true;
        path.push_back(u);
        if (u==target)
            paths.push_back(path);
        else {
            for (int v:graph[u]) {
                help(graph, v, target, path);
            }
        }
        visited[u]=false;
        path.pop_back();
    }
};
