class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        // LCSequence, T:O(NM), S:O(NM)
        // L[i,j] longest subsequence s[:i] t[:j]
        // L[i,j]=max(L[i-1,j-1],L[i,j-1],L[i-1,j])+s[i]==s[j]
        vector<vector<int>> table(s.length()+1, vector<int>(t.length()+1, 0));
        for (int i=1; i<=s.length(); ++i) {
            for (int j=1; j<=t.length(); ++j) {
                if (s[i-1]==t[j-1])
                    table[i][j] = table[i-1][j-1]+1;
                else
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                if (table[i][j]==s.length()) return true;
            }
        }
        // for (int i=0; i<=s.length(); ++i) {
        //     for (int j=0; j<=t.length(); ++j) {
        //         cout<<table[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
        return table[s.length()][t.length()]==s.length();

    }
};

/*
Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

// Eg-1. s="abc", t="bahbgdca"
    // idx=[a={1,7}, b={0,3}, c={6}]
    //  i=0 ('a'): prev=1
    //  i=1 ('b'): prev=3
    //  i=2 ('c'): prev=6 (return true)
*/
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        //T: O(n)+O(MlogN), S:O(n)
        unordered_map<char, vector<int>> m;
        for (int i=0; i<t.length(); ++i)
            m[t[i]].push_back(i);

        int prev=-1;
        for (int i=0; i<s.length(); ++i) {
            vector<int> vec = m[s[i]];
            auto find = upper_bound(vec.begin(), vec.end(), prev);
            if (find != vec.end()) prev = vec[find-vec.begin()];
            else return false;
        }
        return true;

    }
};
