/*
    First, find out the shortest ditance between node x to node n.
    DFS to find restricted path.
    T:O(E+VlogV)/S:O(V)
    -----
    directly dfs to enumerate all possible paths will get TLE.
    Use memoise dfs (kind of dp) instead.

*/

// Dijastra + cache DFS
typedef pair<long,int> pii;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        vector<vector<pii>> graph(n+1,vector<pii>{});
        vector<long> dist(n+1,INT_MAX);
        dist[n]=0;
        for (auto edge:edges) {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({dist[n],n}); // dist, node
        while (!pq.empty()) {
            auto p=pq.top(); pq.pop();
            int u=p.second;
            for (pii vp:graph[u]) { //node, weight
                int v=vp.first, w=vp.second;
                if (dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        vector<int> visited(n+1,-1);
        return dfs(graph,visited,dist,1,n,INT_MAX);
    }

    int dfs(vector<vector<pii>> &graph, vector<int> &visited, vector<long> &dist, int u, int n, long prev)
    {
        int mod=1e9+7;
        if (dist[u]>=prev) return 0;
        else if (visited[u]>=0) return visited[u];
        else if (u==n) return 1;
        int ret=0;
        for (auto vp:graph[u]) {
            ret=(ret%mod+dfs(graph,visited,dist,vp.first,n,dist[u])%mod)%mod;
        }
        visited[u]=ret;
        return ret;
    }
};

// bellman ford + cache DFS
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        vector<long> dist(n+1,INT_MAX);
        dist[n]=0;
        for (int i=1; i<n; ++i) {
            for (auto edge:edges) { // u,v,w
                dist[edge[1]]=min(dist[edge[1]],dist[edge[0]]+(long)edge[2]);
                dist[edge[0]]=min(dist[edge[0]],dist[edge[1]]+(long)edge[2]);
            }
        }
        vector<vector<int>> graph(n+1,vector<int>{});
        vector<bool> visited(n+1,0);
        int ans=0;
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(graph,visited,dist,1,n,INT_MAX,ans);
        return ans;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<long> &dist, int u, int n, long prev, int &ans)
    {
        if (visited[u]) return;
        else if (dist[u]>=prev) return;
        else if (u==n) {ans++; return;}
        visited[u]=true;
        for (int v:graph[u])
            dfs(graph,visited,dist,v,n,dist[u],ans);
        visited[u]=false;
    }
};
