class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num_orange = 0;
        queue<pair<int, int>> que; // for bfs
        int num_r = grid.size();
        int num_c = grid[0].size();
        for (int r = 0; r < num_r; r++) {
            for (int c = 0; c < num_c; c++) {
                if (grid[r][c] == 0)
                    continue;
                num_orange++;
                if (grid[r][c] == 2)
                    que.push({r, c});
            }
        }

        // edge case
        if (num_orange == 0)
            return 0;

        // bfs
        int num_rotten = 0;
        int rotten_times = -1;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!que.empty()) {
            int num_iter = que.size();
            num_rotten += num_iter;
            for (int i=0; i < num_iter; i++) {
                pair<int, int> rotten = que.front();
                que.pop();
                grid[rotten.first][rotten.second] = 2; // turn rotten

                // check adjacent oranges
                for (const auto& dir : dirs) {
                    int r = rotten.first + dir[0];
                    int c = rotten.second + dir[1];
                    if (!boundCheck(r, c, num_r, num_c))
                        continue;
                    if (grid[r][c] == 1) {
                        grid[r][c] = 2; // avoid adding to queue multiple times
                        que.push({r, c});
                    }
                }
            }
            rotten_times++;
        }
        
        return num_rotten == num_orange ? rotten_times : -1;
    }
    bool boundCheck(int r, int c, int num_r, int num_c) {
        if (r < 0 || r >= num_r || c < 0 || c >= num_c)
            return false;
        return true;
    }
        
};

/* 
    bfs
 */