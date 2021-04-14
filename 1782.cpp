/*
    n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]

    1: 2 3 2
    2: 1 4 3 1
    3: 1 2
    4: 2

    to find out incident edges for each pair (edge): simply add the degree of 2 nodes and reduce the duplicate edge.

    Directly implement as description will get TLE.

    USE BINARY SEARCH on the degree of each query !!
*/
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries)
    {
        vector<vector<int>> graph(n+1,vector<int>(n+1,0)); //node -> nodes;
        for (auto edge:edges) {
            graph[edge[0]][edge[1]]++;
            graph[edge[0]][0]++;
            graph[edge[1]][edge[0]]++;
            graph[edge[1]][0]++;
        }
        vector<int> table(edges.size()+1,0);
        for (int i=1; i<=n; ++i) {
            for (int j=i+1; j<=n; ++j) {
                int freq=graph[i][0]+graph[j][0]-min(graph[i][j],graph[j][i]);
                table[freq]++;
            }
        }

        for (int i=1; i<table.size(); ++i) table[i]+=table[i-1];
        vector<int> ans;
        for (int q:queries) {
            ans.push_back(table.back()-table[q]);
        }
        return ans;
    }
};
