/*
    1-d dp solution on 0 ~ n
    dp[i] denotes if Alice will win with n stones
    might get TLE, butwe can see theree's a constraint: 1 <= n <= 10^5
    Thus we might avoid TLE.
    T(n)=T(n-1)+O(sqrt(n))
        =integral x^(1/2) dx
        =x^(3/2)
    S(n)=O(n)
    -----
    7
    0 1 2 3 4 5 6
    0 1 0 1 1 0 1
*/
class Solution {
public:
    bool winnerSquareGame(int n)
    {
        int m=sqrt(n);
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; ++i) {
            int k=sqrt(i);
            for(int j=1; j<=k; ++j) {
                if (dp[i-j*j]) continue;
                dp[i]=1;
                break;
            }
        }
        return dp[n];
    }
};
