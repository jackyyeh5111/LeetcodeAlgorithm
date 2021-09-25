/***** Second Visit *****/
class Solution {
public:
    int dirs[4]={-1,-2,1,2};
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.size()==0|matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans=max(ans,dfs(matrix,dp,i,j,INT_MIN));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int prev)
    {
        int m=matrix.size(), n=matrix[0].size();
        if (i<0||i>=m||j<0||j>=n||matrix[i][j]<=prev) return 0;
        else if (dp[i][j]!=-1) return dp[i][j];
        else {
            for (int dir:dirs)
                dp[i][j]=max(dp[i][j],
                             dfs(matrix,dp,i+dir/2,j+dir%2,matrix[i][j])+1);
            return dp[i][j];
        }
    }
};

/***** First Visit *****/
/*
    brute force:
    dfs on each position T:O(4^mn)/S:O(mn)
    -----
    memoise dfs, i.e. dp approach
    T:O(mn)/S:O(mn)
*/
class Solution {
public:
    int dirs[4]={-2,-1,1,2};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1)); // m x n
        int ans=1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans=max(ans,dfs(matrix, dp, i, j, -1));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y, int prev)
    {
        int m=matrix.size(),n=matrix[0].size();
        if (x<0||x>=m||y<0||y>=n||matrix[x][y]<=prev) return 0;
        else if (dp[x][y]>=0) return dp[x][y];
        int longest=1;
        for (int d:dirs)
            longest=max(longest, dfs(matrix,dp,x+d/2,y+d%2,matrix[x][y])+1);
        dp[x][y]=max(dp[x][y],longest);
        return dp[x][y];
    }
};
