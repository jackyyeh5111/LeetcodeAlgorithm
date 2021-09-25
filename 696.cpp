/*
    "00110011"
     brute force way:
     T:O(n^2)/S:O(1)
     -----
     "00110011"
      ^  ^
     0 and 1 are consecutive
*/
class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int prev=0,ans=0;
        int i=0,n=s.length();
        while (i<n) {
            int j=i;
            while (j+1<n&&s[j+1]==s[j]) j++;
            ans+=min(j-i+1,prev);
            prev=j-i+1;
            i=j+1;
        }
        return ans;
    }
};
