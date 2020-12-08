/*
    String
    1. TRIE if multiple pattern matching
    2. KMP
    3. treat it as array
        Array:
        3-1. 2 ptr
        3-2. moving window
    Here we try to use 2 ptr solution.
    a  b  a  c  c  b  d  e  f  f  e  d
    2. 5.    4.       11 10 9
    _______
       _____________
             ----
                      ----------------
                         ----------
                            ----
    for each char from left, find its corresponding same char from right
    Then split all regions
    T:O(n^2)/S:O(n) Actually space complexity is constant since worst
    case is the vector/map with length 26 (chars.)
*/
class Solution {
public:
    vector<int> partitionLabels(string S)
    {
        unordered_map<char,int> m;
        int n=S.length();
        for (int i=0; i<n; ++i) {
            if (m.find(S[i])!=m.end()) continue;
            int j=n-1;
            for (;j>=i; --j) {
                if (S[j]==S[i]) break;
            }
            // cout<<S[i]<<":"<<j<<endl;
            m[S[i]]=j;
        }
        int k=0, t=0;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            k=max(k,m[S[i]]);
            if (i==k) {
                ans.push_back(i-t+1);
                k++; t=i+1;
            }
        }
        return ans;
    }
};
