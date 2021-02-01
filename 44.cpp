/***** Third Visit *****/
/*
    Typical dp problem as before.
    dp[i][j] denotes s[0-i] matches p[0-j] or not.
    dp[i][j] = dp[i-1][j-1] if s[i]==p[j]
             = true if p[j]=='*'
             = dp[i-1][j-1] if p[j]=='?'
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    T:O(mn)/S:O(mn), could be reduced to linear space.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(), n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=1;
        for (int i=1; i<=n; ++i) dp[0][i]=dp[0][i-1]&&(p[i-1]=='*');
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else if (p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1];
            }
        }
        return dp[m][n];
    }
};

/***** Second Visit *****/
/*
    string:
    1. failure function of KMP
    2. TRIE
    3. treat it as array.
        1. 2 ptr
        2. moving window
    4. other
    -----
    dp[i][j] denotes s[0-i] match p[0-j]
    dp[i][j]=dp[i-1][j-1]&&s[i]==p[j] ||
             dp[i-1][j-1]&&'?'==p[j]  ||
             p[j]=='*'&&dp[i][j-1]|| treat * as empty
             dp[i-1][j]|| treat dp[i] as any incominig seq
             dp[i-1][j-1] treat * as single char.
     dp solution
     T:O(mn)/S:O(mn)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=true;
        for(int i=1; i<=n; ++i) dp[0][i]=p[i-1]=='*'?dp[0][i-1]:0;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if (p[j-1]=='*')
                    dp[i][j]=dp[i-1][j-1]||dp[i][j-1]||dp[i-1][j];
                else
                    dp[i][j]=0;
            }
        }
        return dp[m][n];
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isMatch(string s, string p)
    {
        // dynamic programming
        // T:O(nm), S:O(nm)
        vector<vector<bool>> table(s.size()+1, vector<bool>(p.size()+1,0));
        table[0][0]=true;
        for (int i=0; i<p.length(); ++i) {
            if (p[i]=='*') table[0][i+1] = table[0][i];
        }
        for (int i=1; i<=s.length(); ++i) {
            for (int j=1; j<=p.length(); ++j) {
                if(s[i-1]==p[j-1]||p[j-1]=='?') table[i][j]=table[i-1][j-1];
                else if (p[j-1]=='*') table[i][j]=table[i-1][j]||table[i][j-1]||table[i-1][j-1];
                else table[i][j]=0;
            }
        }
        return table[s.size()][p.size()];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, startIdx = -1, match;
        while (i < m) {
            // * found, only advancing pattern pointer
            if (j < n && p[j] == '*') {
                match = i;
                startIdx = j++;
            }
            // advancing both pointers
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            // fail to match current char but last pattern pointer was *, so roll back to * matchup and start over again by advancing string pointer
            else if (startIdx >= 0) {
                i = ++match;
                j = startIdx + 1;
            }
            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            else return false;
        }
        //check for remaining characters in pattern
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
