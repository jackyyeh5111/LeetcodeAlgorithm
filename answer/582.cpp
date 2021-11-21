/*
    Construct a directed tree and apply dfs to kill all traversed node
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        unordered_map<int,vector<int>> graph;
        unordered_set<int> visited;
        for (int i=0; i<pid.size(); ++i) {
            graph[ppid[i]].push_back(pid[i]);
        }
        vector<int> ans;
        dfs(graph,visited,kill,ans);
        return ans;
    }

    void dfs(unordered_map<int,vector<int>> &graph, unordered_set<int> &visited, int u,
             vector<int> &ans)
    {
        if (visited.count(u)!=0) return;
        ans.push_back(u);
        visited.insert(u);
        for (int v:graph[u])
            dfs(graph,visited,v,ans);
    }
};
