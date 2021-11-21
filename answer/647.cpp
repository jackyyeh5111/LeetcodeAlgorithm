/***** Second Visit *****/
/*
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    int countSubstrings(string s)
    {
        int ans=0,n=s.length();
        for (int i=0; i<n; ++i) {
            int l=i,r=i;
            while (l>=0&&r<n&&s[l]==s[r]) {
                l--; r++;
                ans++;
            }
            l=i;r=i+1;
            while (l>=0&&r<n&&s[l]==s[r]) {
                l--; r++;
                ans++;
            }
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    palindrome checking
    s[i]==s[j]&&dp[i+1][j-1]
    T:O(n^2)/S:O(n^2)
    -----
    reduce SC to O(1) by directively check left/right char.
*/
class Solution {
public:
    int countSubstrings(string s)
    {
        int n=s.length(), ans=0;
        for (int i=0; i<n; ++i) {
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r]) {l--; r++; ans++;}
            l=i; r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]) {l--; r++; ans++;}
        }
        return ans;
    }
};
