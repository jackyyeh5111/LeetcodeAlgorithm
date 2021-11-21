/*
    string processing:
    1. TRIE
    2. KMP

    abcabcabc
    000123456

    abab
    0012

    abac
    0010

    abcab
    00012

    aabaab
    010123

    aaa
    012

    check the last value is the multiple of first N chars?
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int n=s.length();
        if (n==1) return false;
        vector<int> failure(n,0);
        for(int i=1; i<n; ++i) {
            int j=failure[i-1];
            while(j>0&&s[i]!=s[j]) j=failure[j-1];
            if (s[i]==s[j]) failure[i]=j+1;
            else failure[i]=0;
        }

        return failure[n-1]>0&&failure[n-1]%(n-failure[n-1])==0;
    }
};

/***** Another Approach *****/
/*
    origin_str = pattern + pattern + ... + pattern =  m * pattern;
    origin_str + origin_str = 2 * m * pattern;
    new_str = pattern_wo_head + (2m-2) * pattern + pattern_wo_rear
    origin_str(m * pattern) could be found in new_str if m >= 2.
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
     return (s+s).substr(1,s.length()*2-2).find(s)!=-1;
    }
};
