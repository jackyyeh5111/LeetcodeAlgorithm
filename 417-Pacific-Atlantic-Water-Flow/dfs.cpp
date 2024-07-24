class Solution {
public:
    vector<vector<bool>> visited_p, visited_a;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_r = heights.size();
        int num_c = heights[0].size();
        visited_p.resize(num_r, vector<bool>(num_c));
        visited_a.resize(num_r, vector<bool>(num_c));

        // check locations that flow to pacific
        for (int r = 0; r < num_r; r++) {
            dfs(r, 0, visited_p, heights);
            dfs(r, num_c - 1, visited_a, heights);
        }
        for (int c = 0; c < num_c; c++) {
            dfs(0, c, visited_p, heights);
            dfs(num_r - 1, c, visited_a, heights);
        }
        
        // check locations that flow to both
        vector<vector<int>> ans;
        for (int r = 0; r < num_r; r++) {
            for (int c = 0; c < num_c; c++) {
                if (visited_p[r][c] && visited_a[r][c])
                    ans.push_back({r, c});
            }
        }
        return ans;
        
    }
    void dfs(int row, int col, vector<vector<bool>> &visited, const vector<vector<int>>& heights) {
        if (visited[row][col])
            return;   
        int num_r = heights.size();
        int num_c = heights[0].size();
        
        visited[row][col] = true;
        vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (auto dir : dirs) {
            int next_r = row + dir[0];
            int next_c = col + dir[1];
            
            // boundary check
            if (next_r < 0 || next_r >= num_r || next_c < 0 || next_c >= num_c)
                continue;
            if (heights[next_r][next_c] < heights[row][col])
                continue;
            dfs(next_r, next_c, visited, heights);
        }
    }
};

/* 
    heights:
        1 1 4
        1 4 1
        4 1 1
 */