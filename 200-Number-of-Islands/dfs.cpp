class Solution {
public:
    vector<vector<bool>> visited;
    int numIslands(vector<vector<char>>& grid) {
        int num_r = grid.size();
        int num_c = grid[0].size();
        visited.resize(num_r, vector<bool>(num_c));

        int cnt = 0;
        for (int r  = 0; r < num_r; ++r) {
            for (int c  = 0; c < num_c; ++c) {
                if (grid[r][c] == '0' || visited[r][c])
                    continue;
                dfs(grid, r, c);
                ++cnt;
            }
        }
        return cnt;
    }
    void dfs(const vector<vector<char>>& grid, int raw_r, int raw_c) {
        if (visited[raw_r][raw_c])
            return;
        
        visited[raw_r][raw_c] = true;
        int num_r = grid.size();
        int num_c = grid[0].size();
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int r = raw_r + dir[0];
            int c = raw_c + dir[1];
            if (r < 0 || c < 0 || r >= num_r || c >= num_c)
                continue;
            if (grid[r][c] == '0' || visited[r][c])
                continue;
            dfs(grid, r, c);
        }
    }
};