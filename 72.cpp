/***** Third Visit *****/
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m=word1.size(), n=word2.size();
        vector<int> dp(n+1,0);
        for (int j=1; j<=n; ++j) dp[j]=dp[j-1]+1;
        for (int i=1; i<=m; ++i) {
            int prev=dp[0]; dp[0]+=1;
            for (int j=1; j<=n; ++j) {
                int k=dp[j];
                dp[j]=min(min(dp[j-1],dp[j])+1,
                          prev+(word1[i-1]!=word2[j-1]));
                prev=k;
            }
        }
        return dp[n];
    }
};

/***** Second Visit *****/
/*
    string editting
    2-DP solution
    dp[i][j] denotes min ops from word1[0-i] to word2[0-j]
    do[i][j]= max(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+word1[i-1]!=word2[j-1])
        - dp[i-1][j]+1: delete
        - dp[i][j-1]+1: insert
        - dp[i-1][j-1]+word1[i-1]!=word2[j-1]: replace
    T:O(mn)/S:O(mn)
    -----
    reduce to 1-d dp
    T:O(mn)/S:O(1)
*/

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int n1=word1.size(), n2=word2.size();
        vector<int> dp(n2+1, 0);
        for (int i=1; i<=n2; ++i) dp[i]=dp[i-1]+1;
        for (int i=1; i<=n1; ++i) {
            int prev=dp[0]; dp[0]++;
            for (int j=1; j<=n2; ++j) {
                int tmp=dp[j];
                dp[j]=min(min(dp[j]+1,dp[j-1]+1),prev+(word1[i-1]!=word2[j-1]));
                prev=tmp;
            }
        }
        return dp[n2];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int n1=word1.size(), n2=word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for (int i=1; i<=n2; ++i) dp[0][i]=dp[0][i-1]+1;
        for (int i=1; i<=n1; ++i) {
            dp[i][0]=dp[i-1][0]+1;
            for (int j=1; j<=n2; ++j) {
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(word1[i-1]!=word2[j-1]));
            }
        }
        return dp[n1][n2];
    }
};

/***** First Visit *****/
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
