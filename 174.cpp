/*
If we start from left top, in addition to minimize initial HP required to get (i,j), we also have to maximize HP left when we get (i,j) in order to decide whether we need more initial HP in the next step. It doesn't directly depend on things at (i-1,j) and (i,j-1).
*/
class Solution {
public:
    // T:O(n^2), S:O(n)
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<int> dp(n+1,INT_MAX);
        dp[n-1]=1;
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                dp[j]=max(1,min(dp[j],dp[j+1])-dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
