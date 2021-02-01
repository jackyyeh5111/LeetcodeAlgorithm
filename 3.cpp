/***** Second Visit *****/
/*
    abcabcbb
           ^
           ^
    sliding window.
    T:O(n)/S:O(26)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int table[256], n=s.length(), ans=0, l=0;
        for (int i=0; i<256; ++i) table[i]=-1;
        for (int r=0; r<n; ++r) {
            if (table[s[r]]>=0)
                l=max(l,table[s[r]]+1);
            table[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    Note that we are searching longest SUBSTRING, which is consecutive.
    brute force
    iterate over each substring
    T:O(n^2)/S:O(1)
    --------
    use a moving hashmap. k:char. v: idx
    T:O(n) 1 pass / S:O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> m;
        int n=s.length(),ans=0,x=-1;
        for (int i=0; i<n; ++i) {
            char c=s[i];
            if (m.find(c)!=m.end()) {
                x=max(x,m[c]);
            }
            m[c]=i;
            ans=max(ans,i-x);
        }
        return ans;
    }
};
