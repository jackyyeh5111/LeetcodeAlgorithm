class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        // find shortest path
        // dijkstra, bellman-ford, floyd-warshall, johnson's

        // init O(v+e)
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        vector<int> tmp=dist;

        for (int i=0; i<=K; ++i) {
            for (auto flight:flights){
                if ((double)dist[flight[0]]+(double)flight[2]<(double)dist[flight[1]]) {
                    tmp[flight[1]]=min(dist[flight[0]]+flight[2],tmp[flight[1]]);
                    // cout<<dist[flight[0]]+flight[2]<<endl;
                }
            }
            dist=tmp;
            // for (int x:dist) cout<<x<<",";
            // cout<<endl;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
