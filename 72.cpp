/*************** String editing 1-d dp ********************/
class Solution {
public:
    int minDistance(string word1, string word2)
    {
         // typical dp problem: string editing.
         // induction: dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
         // init: dp[0][i] = dp[0][i-1]+1;
        vector<int> dp(word2.length()+1,0);
        for (int j=0; j<=word2.size(); ++j) dp[j]=j;
        for (int i=1; i<=word1.size(); ++i) {
            int prev=dp[0];
            dp[0]=i;
            for (int j=1; j<=word2.size(); ++j) {
                int cost = !(word1[i-1]==word2[j-1]);
                int tmp=dp[j];
                dp[j]=min(min(dp[j-1]+1,dp[j]+1),prev+cost);
                prev=tmp;
            }
        }
        return dp[word2.size()];
    }
};

/*************** String editing 2-d dp ********************/
class Solution {
public:
    int minDistance(string word1, string word2)
    {
         //T:O(n)
         // typical dp problem: string editing.
         // induction: dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
         // init: dp[0][i] = dp[0][i-1]+1;
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,0));
        for (int i=0; i<=word1.size(); ++i) dp[i][0]=i;
        for (int j=0; j<=word2.size(); ++j) dp[0][j]=j;
        for (int i=1; i<=word1.size(); ++i) {
            for (int j=1; j<=word2.size(); ++j) {
                int cost = !(word1[i-1]==word2[j-1]);
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+cost);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
