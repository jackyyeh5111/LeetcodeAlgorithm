/***** Third Visit *****/
/*
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
    dp[i][j] denotes s[0-i-1] matches p[0-j-1]
    if p[j] is char  dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1]
    if p[j] is .     dp[i][j]=dp[i-1][j-1]
    if p[j] is *     dp[i][j]=dp[i][j-2]||dp[i-1][j] if p[j-1] is checked alpha or .
*/
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int sn=s.length(), pn=p.length();
        vector<vector<bool>> dp(sn+1,vector<bool>(pn+1,0));
        dp[0][0]=1;
        for (int j=1; j<=pn; ++j) dp[0][j]=p[j-1]=='*'&&dp[0][j-2];
        for (int i=1; i<=sn; ++i) {
            for (int j=1; j<=pn; ++j) {
                if (isalpha(p[j-1])) dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1];
                else if (p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.');
            }
        }
        return dp[sn][pn];
    }
};

/***** Second Visit *****/
/*
    dp[i][j]: s[0-i] match p[0-j] or not.
    dp[i][j]
        a-z s[i]==p[j] && dp[i-1][j-1]
        .   dp[i-1][j-1]
        *   s[i]==p[j-k] || dp[i][j-1]
    Note for string s, we should consider empty string
    e.g. "" "a*" -> true
*/
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=1;
        for (int i=0; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (isalpha(p[j-1])) {
                    dp[i][j]=i&&dp[i-1][j-1]&&s[i-1]==p[j-1];
                }
                else if (p[j-1]=='.') {
                    dp[i][j]=i&&dp[i-1][j-1];
                }
                else {
                    dp[i][j]=dp[i][j-2]||(i&&dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
            }
        }
        return dp[m][n];
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isMatch(string s, string p) {
        // LCS variationn
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
    /*
    We define dp[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. The state equations will be:

    dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
    dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
    */
};
