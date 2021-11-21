/*
    Take nums from left/right, score is to sum the rest of them.
    Alice first
    Alice maximize score while Bob minimize score.
    -----
    [5,3,1,4,2] sum=15
    13 8
    9 5
    -----
    brute force:
    enumerate all possible combinations
    T:O(2^n)
    -----
    [1,2,3] // A,B
     (0,0) (2,0) (5,3)
           (0,0) (3,0)
                 (0,0)
    [1,2,3,4] // A,B
     (0,0) (2,0) (5,3) (13,7)
           (0,0) (3,0) (7,4)
                 (0,0) (4,0)
                       (0,0)
    -----
    dp[i][j] denotes the score of A,B w. max diff and starts by A.
    retrun dp[0,n].first-dp[0,n].second
    Each player needs to play optimally to get as many points as possible and make the other player get as less as possible.
    So the game is actually the same for both of them.
    T:O(n^2)/S:O(n^2)
    -----
    Sounds like a search problem. Try a stone from each side, and recursively calculate the difference. Maximize the difference among two choices to play optimally.

    We can memoise the results for the start (i) and end(j) of the remaining stones.
    T:O(n^2)/S:O(n^2)
*/
// DP
class Solution {
public:
    int stoneGameVII(vector<int>& stones)
    {
        int n=stones.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        for (int len=1; len<n; ++len) {
            int csum=0;
            for (int k=0; k<len; ++k) csum+=stones[k];
            int prev=0;
            for (int i=0; i+len<n; ++i) {
                int j=i+len;
                csum+=(stones[j]-prev);
                if (csum-stones[i]+dp[i+1][j].second-dp[i+1][j].first>dp[i][j].first-dp[i][j].second) {
                    dp[i][j].first=csum-stones[i]+dp[i+1][j].second;
                    dp[i][j].second=dp[i+1][j].first;
                }
                if (csum-stones[j]+dp[i][j-1].second-dp[i][j-1].first>dp[i][j].first-dp[i][j].second) {
                    dp[i][j].first=csum-stones[j]+dp[i][j-1].second;
                    dp[i][j].second=dp[i][j-1].first;
                }
                prev=stones[i];

            }
        }
        return dp[0][n-1].first-dp[0][n-1].second;
    }
};

// backtracking
class Solution {
public:
    int dp[1001][1001] = {};
    int dfs(vector<int>& s, int i, int j, int sum)
    {
        if (i == j)
            return 0;
        if (dp[i][j]) return dp[i][j];
        dp[i][j]=max(
            sum-s[i]-dfs(s, i+1, j, sum-s[i]),
            sum-s[j]-dfs(s, i, j-1, sum-s[j])
        )
        return dp[i][j];
    }
    int stoneGameVII(vector<int>& s)
    {
        int sum=accumulate(s.begin(), s.end(), 0);
        return dfs(s, 0, s.size() - 1, sum);
    }
};
