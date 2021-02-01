/*
    DFS on undirected graph and check directed connection.
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> udgraph(n,vector<int>());
        vector<unordered_set<int>> dgraph(n,unordered_set<int>());
        vector<bool> visited(n,0);
        for (auto edge:connections) {
            udgraph[edge[0]].push_back(edge[1]);
            udgraph[edge[1]].push_back(edge[0]);
            dgraph[edge[0]].insert(edge[1]);
        }
        int ans=0;
        dfs(udgraph,dgraph,visited,0,-1,ans);
        return ans;
    }

    void dfs(vector<vector<int>> &udgraph, vector<unordered_set<int>> &dgraph,
             vector<bool> &visited, int u, int prev, int &ans)
    {
        if (visited[u]) return;
        visited[u]=true;
        if (prev!=-1&&dgraph[u].count(prev)==0) ans++;
        for (int v:udgraph[u])
            dfs(udgraph,dgraph,visited,v,u,ans);
    }
};
