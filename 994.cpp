class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        int num_oranges = 0;
        int num_rotten = 0;
        queue<pair<int, int>> que;
        for (int r = 0; r < n_row; r++) {
            for (int c = 0; c < n_col; c++) {
                if (grid[r][c] == 2) {
                    num_rotten++;
                    que.push(make_pair(r, c));
                }
                if (grid[r][c] != 0) num_oranges++;
            }
        }

        int elapse = 0;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!que.empty() && num_rotten != num_oranges) {
            int num_iter = que.size();
            for (int i = 0; i < num_iter; i++) {
                auto [cur_r, cur_c] = que.front();
                que.pop();
                
                // spread four adjcents cells
                for (const auto dir : dirs) {
                    int next_r = cur_r + dir[0];
                    int next_c = cur_c + dir[1];
                    if (!checkBoundary(cur_r, cur_c, next_r, next_c, n_row, n_col))
                        continue;
                    if (grid[next_r][next_c] != 1) 
                        continue;
                    grid[next_r][next_c] = 2; // become rotten
                    que.push(make_pair(next_r, next_c));
                    num_rotten++;
                }
            }
            elapse++;
        }
        return num_rotten != num_oranges ? -1 : elapse;
    }
    bool checkBoundary(int cur_r, int cur_c, int next_r, int next_c, int n_row, int n_col) {
        return next_r >= 0 && next_c >= 0 && next_r < n_row && next_c < n_col;
    }
};

/* 
    1. check # of rotten
    2. bfs to get other oranges rotten until all oranges become rotten
 */