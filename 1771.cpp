/*
    The trick is to how to enforce the rule that characters should come from the both strings.
    So, we run the base algorithm on the concatenated string. At this point, our tabulation dp stores all interim solutions.
    Then, we reuse the tabulation dp and only consider i and j where w1[i] == w2[j].
    As additional optimization, we only need consider one case when w1[i] == w2[j]. For that, we pick the smallest i and the largest j.
    -----
    Longest subsequence finding on concat string: T:O((m+n)^2)
    Check the value of dp for each word1[i]==word2[j] to ensure non-empty subsequence: T:O(mn)
    T:O((m+n)^2)/S:O((m+n)^2)
*/
class Solution {
public:
    int longestPalindrome(string word1, string word2)
    {
        // Longest subsequence finding
        int m=word1.length(), n=word2.length();
        vector<vector<int>> dp(m+n+2, vector<int>(m+n+2,0));
        string concat=word1+word2;
        for (int len=1; len<=m+n; ++len) {
            for (int i=1; i+len-1<=m+n; ++i) {
                int j=i+len-1;
                dp[i][j]=concat[i-1]==concat[j-1]?
                    dp[i+1][j-1]+(len==1?1:2):max(dp[i+1][j],dp[i][j-1]);
            }
        }
        // Ensure non-empty subsequence
        int ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=n-1; j>=0; j--) {
                if (word1[i]==word2[j]) {
                    int k=m+j;
                    ans=max(ans,dp[i+1][k+1]);
                    break;
                }
            }
        }
        return ans;
    }
};
