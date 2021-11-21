/*
    dp solution
    dp[i][j] denotes ways to assign symbols to make sum equal to j w. 0 to i nodes.
    T:O(2000n)/S:O(2000n)
    -----
    0/1 knapsack
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if (S>1000) return 0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,0));
        dp[0][1000]=1;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=2000; ++j) {
                if (j-nums[i-1]>=0)
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                if (j+nums[i-1]<=2000)
                    dp[i][j]+=dp[i-1][j+nums[i-1]];
            }
        }
        return dp[n][S+1000];
    }
};
