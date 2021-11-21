/*
    DP[r][c1][c2]: The maximum cherries that both robots can take starting on the r th row, and column c1 and c2 of Robot 1 and 2 respectively.
    Use BOTTOM-UP for backtracking the max candies we can collect in position 0 and n-1.
*/

// Top-down thinking. Still need to know the max gained candies in next row, thus either backtracking or bottom-up.
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size();
        int ***dp=new int**[m];
        for (int i=0; i<m; ++i) {
            dp[i]=new int*[n];
            for (int j=0; j<n; ++j) {
                dp[i][j]=new int[n];
                for (int k=0; k<n; ++k)
                    dp[i][j][k]=-1;
            }
        }
        return dfs(grid,dp,m,n,0,0,n-1);
    }

    int dfs(vector<vector<int>>& grid, int ***dp, int m, int n, int r, int c1, int c2)
    {
        if (r==m) return 0;
        if (dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int ans=0;
        for (int i=-1; i<=1; ++i) {
            for (int j=-1; j<=1; ++j) {
                int cc1=c1+i, cc2=c2+j;
                if (cc1<0||cc1>=n||cc2<0||cc2>=n) continue;
                ans=max(ans,dfs(grid,dp,m,n,r+1,cc1,cc2));
            }
        }
        ans+=grid[r][c1];
        if (c1!=c2) ans+=grid[r][c2];
        dp[r][c1][c2]=ans;
        return ans;
    }
};
