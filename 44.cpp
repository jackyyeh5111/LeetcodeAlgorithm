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
                j = asterick + 1;
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
