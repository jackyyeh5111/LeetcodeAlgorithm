/*
    n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
    consider it as an undirected graph, we can start postDFS from node 0.
    Meanwhile, conduct a moving multiset to count the frequency of each char.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<vector<int>> graph(n,vector<int>{});
        vector<int> visited(n,0); // 0: non visit, 1: visiting, 2: done
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n,1);
        postDFS(graph, visited, 0, ans, labels);
        return ans;
    }

    // return cnt
    vector<int> postDFS(vector<vector<int>> &graph, vector<int> &visited, int u,
                 vector<int> &ans, string &labels)
    {
        if (visited[u]!=0) return vector<int>(26,0);
        visited[u]=1;
        vector<int> cnt(26,0);
        for (int v:graph[u]) {
            auto sub=postDFS(graph,visited,v,ans,labels);
            for (int i=0; i<26; ++i) cnt[i]+=sub[i];
        }
        cnt[labels[u]-'a']++;
        ans[u]=cnt[labels[u]-'a'];
        visited[u]=2;
        return cnt;
    }
};
