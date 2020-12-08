/*
    First, we can have numRows of vector<char>.

    0 1 2 3 4 5 6
    P     I     N
    A   L S   I G
    Y A   H R
    P     I

    P A Y P A L I S H I R  I  N  G
    0 1 2 3 4 5 6 7 8 9 10 11 12 13
              ^
    SORT by row
    T:O(n)/S:O(n)
    ---------
    VISIT by row
    T:O(n)/S:O(1)
*/

/****** SORT by row ******/
class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows==1) return s;
        vector<vector<char>> v(numRows,vector<char>{});
        int n=s.length();
        for (int i=0; i<n; ++i) {
            int d=2*numRows-2;
            if (i%d<numRows) v[i%d].push_back(s[i]);
            else v[2*numRows-2-i%d].push_back(s[i]);
        }
        string ans="";
        for (int i=0; i<numRows; ++i) {
            int k=v[i].size();
            for (int j=0; j<k; ++j) ans+=v[i][j];
        }
        return ans;
    }
};


/****** VISIT by row ******/
class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows==1) return s;
        int n=s.length();
        int cycle=2*numRows-2;
        string ans="";
        for (int i=0; i<numRows; ++i) {
            for (int j=i; j<n; j+=cycle) {
                ans+=s[j];
                if (i>0&&i<numRows-1&&j+cycle-2*i<n)
                    ans+=s[j+cycle-2*i];
            }
        }
        return ans;
    }
};
