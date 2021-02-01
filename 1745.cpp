/*
    T:O(n^2)+O(n^2)/S:O(n^2)
*/
class Solution {
public:
    bool checkPartitioning(string s)
    {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n,0));
        for (int len=1; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j=i+len-1;
                if (i==j||(i+1==j&&s[i]==s[j])) dp[len][i]=1;
                else {
                    dp[len][i]=dp[len-2][i+1]&&s[i]==s[j];
                }
            }
        }
        for (int len1=1; len1<=n-2; ++len1) {
            for (int len2=1; len1+len2<=n-1; ++len2) {
                int len3=n-len1-len2;
                if (dp[len1][0]&&dp[len2][len1]&&dp[len3][len1+len2]) return true;
            }
        }
        return false;
    }
};
