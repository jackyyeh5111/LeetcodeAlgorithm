/*
    informTime 0-10000
    n 1-100000


    e.g.
    0<->1...<->999999
    worst case: 999999 * 10000
    ignore: integer overflow

    -----
    manager[0] = 5, 0<->5==inforTime[0] ?
    directed graph
    n=3, return 10, return 5(V)
    [5] 0, 1 2
    [1] 1
    [2] 2

    n=4, return 7(V)
    [5] 0, 1 2
    [1] 1
    [2] 2, 3
    [3]

    graph building
    T:O(V+E) V:n, E: size of manager / S:O(V+E)

    DFS T:O(V+E)
    -----

*/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> graph(n,vector<int>{});
        vector<bool> visited(n,0);
        for (int i=0; i<n; ++i) {
            if (manager[i]==-1) continue;
            graph[manager[i]].push_back(i);
        }

        int cmax=0;
        dfs(graph,visited,headID,0,cmax,informTime);
        return cmax;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u, int ctime, int &cmax, vector<int> &informTime)
    {
        if (visited[u]) return;
        visited[u]=1;
        cmax=max(cmax,ctime);
        for (const int &v:graph[u])
            dfs(graph,visited,v,ctime+informTime[u],cmax,informTime);
    }

};
