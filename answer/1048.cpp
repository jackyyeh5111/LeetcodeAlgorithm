/*
    Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.
    Return the longest possible length of a word chain with words chosen from the given list of words

    How to find predecessor connection?
    T:O(n^2*k+n)/S:O(n)
*/

// use dp on longest path search.
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n=words.size();
        vector<vector<int>> graph(n,vector<int>{});
        vector<int> dp(n,-1);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int x=i,y=j;
                if (words[x].length()==words[y].length()+1) swap(x,y);
                else if (words[x].length()+1!=words[y].length()) continue;
                bool feasible=false;
                for (int k=0; k<words[y].length(); ++k) {
                    if (words[x]==words[y].substr(0,k)+words[y].substr(k+1)) {
                        feasible=true;
                        break;
                    }
                }
                if (feasible) graph[x].push_back(y);
            }
        }

        int ans=0;
        for (int i=0; i<n; ++i)
            ans=max(ans,dfs(graph,dp,i));

        return ans;
    }

    // dp[i] denotes max length of path from node i.
    int dfs(vector<vector<int>> &graph, vector<int> &dp, int u)
    {
        if (dp[u]!=-1) return dp[u];
        int ret=0;
        for (int v:graph[u]) ret=max(ret,dfs(graph,dp,v));
        return dp[u]=ret+1;
    }
};

// Directly using dp, sort first.
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n=words.size(),ans=1;
        sort(words.begin(),words.end(),[](auto &a, auto &b){return a.length()<b.length();});
        vector<int> dp(n,1);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int x=i,y=j;
                if (words[x].length()==words[y].length()+1) swap(x,y);
                else if (words[x].length()+1!=words[y].length()) continue;
                bool feasible=false;
                for (int k=0; k<words[y].length(); ++k) {
                    if (words[x]==words[y].substr(0,k)+words[y].substr(k+1)) {
                        feasible=true;
                        break;
                    }
                }
                if (feasible) {
                    dp[y]=max(dp[x]+1,dp[y]);
                    ans=max(ans,dp[y]);
                }
            }
        }

        return ans;
    }
};
