/* 
    More elegant
 */
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for (int i=1; i <= n; ++i) {
            if (i % 2) // odd
                dp[i] = dp[i >> 1] + 1;
            else
                dp[i] = dp[i >> 1];
        }
        return dp;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        if (n == 0) return ans;
        ans[0] = 0;
        ans[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i * 2 <= n)
                ans[i * 2] = ans[i];
            if (i * 2 + 1 <= n)
                ans[i * 2 + 1] = ans[i] + 1;
        }
        return ans;
    }
};