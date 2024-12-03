class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] += dp[k-1] * dp[i-(k+1)+1];
            }
        }
        return dp[n];
    }
};
/* 
        0 1 2 3 4
    dp: 1 1

    1 2 ... n

    if i pick k as the root

          k
        /   \
    1~k-1   k+1~n

    transfer:
    dp[k] = dp[k-1] * dp[n-(k+1)+1]

 */