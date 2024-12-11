class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        pair<int, int> start, end;
        int num_should_visit = 0;
        for (int r = 0; r < n_row; r++) {
            for (int c = 0; c < n_col; c++) {
                if (grid[r][c] == -1) continue;
                if (grid[r][c] == 1) start = {r, c};
                num_should_visit++;
            }
        }
        return dfs(grid, start.first, start.second, 0, num_should_visit);
    }
    int dfs(vector<vector<int>>& grid, int row, int col, int num_visited, int num_should_visit) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        if (row < 0 || row >= n_row || col < 0 || col >= n_col)
            return 0;
        if (grid[row][col] == -1) // obstacle
            return 0;
        num_visited++;
        if (grid[row][col] == 2) {
            /* important here */
            if (num_visited == num_should_visit) return 1;
            return 0;
        }
        
        grid[row][col] = -1; // visiting
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int sum = 0;
        for (const auto& dir : dirs) {
            int next_row = row + dir[0];
            int next_col = col + dir[1];
            sum += dfs(grid, next_row, next_col, num_visited, num_should_visit);
        }
        grid[row][col] = 0; // finish visiting
        return sum;
    }
};