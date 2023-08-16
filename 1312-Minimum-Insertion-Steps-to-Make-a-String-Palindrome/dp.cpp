class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; i++) 
            dp[i][i] = 0;
        
        // transfer function
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i <= N - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) // first and last character are the same
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
            }
        }
        return dp[0][N-1];
    }
};

/* 
    mbadm

    dp[i][j]: the minimum number of steps to make s[i:j] palindrome.

    mbam --> m[ba]m        --> dp[i+1][j-1]
    mbb --> [mb]b or m[bb] --> min(dp[i][j-1], dp[i+1][j]) + 1

       m b a d m
    m  0 1 2 3 2
    b. 1 0 1 2 3
    a.   1 0 1 2
    d.     1 0 1
    m.       1 0

   1. Check the substring of any length to find how many insertions that it needs to become palindrome.
 */