class Solution {
public:
    int numTrees(int n) {
        // top-down 
        if (n <= 1) return 1;
        
        int ans = 0;
        for (int k = 1; k <= n; k++)
            ans += numTrees(k-1) * numTrees(n-k);
        return ans;
    }
};
/* 
    1 2 ... n

    if i pick k as the root

          k
        /   \
    1~k-1   k+1~n

    transfer:
    dp[k] = dp[k-1] * dp[n-(k+1)+1]

 */