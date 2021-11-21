/*
    dp[k][m][n]
    k<= size of strs
    m=0~m, n=0~n

    0/1 knapsack
    T:O(kmn)/S:O(kmn)
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int k=strs.size();
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        int ans=0;
        for (int i=1; i<=k; ++i) {
            int x=0,y=0;
            for (char c:strs[i-1]) {x+=c=='0'; y+=c=='1';}
            for (int p=0; p<=m; ++p) {
                for (int q=0; q<=n; ++q) {
                    if (p<x||q<y) {dp[i][p][q]=dp[i-1][p][q]; continue;}
                    dp[i][p][q]=max(dp[i-1][p-x][q-y]+1,dp[i-1][p][q]);
                    ans=max(ans,dp[i][p][q]);
                }
            }
        }
        return ans;
    }
};
