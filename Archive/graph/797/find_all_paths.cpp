class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<int> path;
        vector<bool> visited(graph.size(),false);
        vector<vector<int>> result;
        DFS(graph, visited, 0, path, result);
        return result;
    }

    void DFS(vector<vector<int>>& graph,
             vector<bool>& visited,
             int i,
             vector<int>& path,
             vector<vector<int>>& result)
    {
        path.push_back(i);
        visited[i] = true;
        if(i==graph.size()-1){
            result.push_back(path);
        }
        else{
            for (int next : graph[i]){
                if(visited[next]) continue;
                DFS(graph, visited,next,path,result);
            }
        }
        visited[i] = false;
        path.pop_back();
    }


};
