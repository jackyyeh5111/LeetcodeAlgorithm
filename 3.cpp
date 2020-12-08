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
