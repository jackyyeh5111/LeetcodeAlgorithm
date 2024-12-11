/* 
    DP
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        if (grid[n_row - 1][n_col - 1] == 1 || grid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(n_row + 1, vector<int>(n_col + 1));
        dp[1][1] = 1;
        for (int r = 1; r <= n_row; r++) {
            for (int c = 1; c <= n_col; c++) {
                if (r == 1 && c == 1) continue;
                if (grid[r-1][c-1] == 1) continue;
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[n_row][n_col];
    }
};


/* dfs */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return dfs(obstacleGrid, 0, 0);
    }
    int dfs(const vector<vector<int>>& grid, int row, int col) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        // check boundary
        if (row < 0 || row >= n_row || col < 0 || col >= n_col)
            return 0;
        if (grid[row][col] == 1) // obstacle
            return 0;
        if (row == n_row-1 && col == n_col - 1)
            return 1;
        return dfs(grid, row + 1, col) + dfs(grid, row, col + 1);
    }
};