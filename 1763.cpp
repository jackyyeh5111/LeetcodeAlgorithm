/*
    divide and conquer
    average T:O(nlogn)/S:O(n)
    worst T:O(n^2)/S:O(n)
*/
class Solution {
public:
    string longestNiceSubstring(string s)
    {
        vector<int> cnt(26,0);
        int n=s.length();
        for (char c:s) {
            if (c==tolower(c)) cnt[c-'a']|=1;
            else cnt[tolower(c)-'a']|=2;
        }

        for (int i=0; i<n; ++i) {
            if (cnt[tolower(s[i])-'a']!=3) {
                string left=longestNiceSubstring(s.substr(0,i));
                string right=i<n-1?longestNiceSubstring(s.substr(i+1)):"";
                return left.length()>=right.length()?left:right;
            }
        }
        return s;
    }
};
