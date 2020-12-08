/***** Second Visit *****/
/*
    2-D: T:O(mn)/S:O(1) in-place
    grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]
    1-D: T:O(mn)/S:O(n) 
    dp[i]=min(dp[i-1],dp[i])+grid[i][j]
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.size()==0||grid[0].size()==0) return 0;
        int m=grid.size(),n=grid[0].size();
        for (int i=1; i<n; ++i) grid[0][i]+=grid[0][i-1];
        for (int i=1; i<m; ++i) {
            grid[i][0]+=grid[i-1][0];
            for (int j=1; j<n; ++j) {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

/***** First Visit *****/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // Same idea with prob.63
        // 1-d DP solution
        vector<int> table(grid[0].size(), 0);
        table[0]=grid[0][0];
        for (int i=1; i<grid[0].size(); ++i){ table[i]=table[i-1]+grid[0][i]; }
        for (int i=1; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (j==0) table[0]+=grid[i][0];
                else table[j]=min(table[j-1], table[j])+grid[i][j];
            }
        }
        return table[grid[0].size()-1];

    }
};
