/***** Fourth Visit *****/
/*
    "abcabcbb"
     ^
        ^
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool table[256]={0};
        int l=0,ans=0,n=s.length();
        for (int i=0; i<n; ++i) {
            while (table[s[i]])
                table[s[l++]]=0;
            table[s[i]]=1;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.length(), ans=0, l=0;
        for (int i=0; i<n; ++i) {
            if (mp.count(s[i]))
                l=max(l,mp[s[i]]+1);
            mp[s[i]]=i;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

/***** Third Visit *****/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans=0,n=s.length(),l=0;
        unordered_map<char,int> mp;
        for (int i=0; i<n; ++i) {
            if (mp.count(s[i])) l=max(l,mp[s[i]]+1);
            mp[s[i]]=i;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

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
