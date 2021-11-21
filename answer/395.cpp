/*
    Divide & Conquer
    T:O(n^2)/S:O(n)
*/
class Solution {
public:
    int longestSubstring(string s, int k)
    {
        int table[26]={0};
        for (char c:s) table[c-'a']++;
        int idx=0;
        while (idx<s.length()&&table[s[idx]-'a']>=k) idx++;
        if (idx==s.length()) return s.length();
        int l = longestSubstring(s.substr(0,idx),k);
        int r = longestSubstring(s.substr(idx+1),k);
        return max(l,r);
    }
};
