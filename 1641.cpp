
/*
    a e i o u
    aa ae ai ao au ee ei eo eu ii io iu oo ou uu
    aaa aae aai aao aau
    -----
    Combination
    Use four | to divide the string into five parts, and each part only contain
    a kind of char or empty. Such as aaa|eee|iiiii|ooooooo|uu.
*/

// combination
class Solution {
public:
    int countVowelStrings(int n) {
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
};

// dp
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,0));
        dp[1][1]=1;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=5; ++j) {
                if (i==1) dp[i][j]=dp[i][j-1]+1;
                else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n][5];
    }
};