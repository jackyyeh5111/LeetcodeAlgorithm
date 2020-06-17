class Solution {
public:
    int climbStairs(int n)
    {
        // typical fibnoci number problem
        // we can have a dp table dp[n] which means distinct ways to get n.
        // then we have induction: dp[n-1]+dp[n-2]
        // now we see its fibnoci.
        vector<int> dp(n+1,0);
        dp[0]=1; dp[1]=1;
        for (int i=2; i<=n; ++i) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
