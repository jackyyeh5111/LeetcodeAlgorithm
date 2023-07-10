class Solution {
public:
    vector<vector<int>> reached;
    vector<vector<bool>> visited;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_r = heights.size();
        int num_c = heights[0].size();
        reached.resize(num_r, vector<int>(num_c));
        visited.resize(num_r, vector<bool>(num_c));
        for (int r = 0; r < num_r; ++r) {
            dfs(heights, r, 0);
        }
        for (int c = 0; c < num_c; ++c) {
            dfs(heights, 0, c);
        }

        // atlantic
        visited.clear();
        visited.resize(num_r, vector<bool>(num_c));
        for (int r = 0; r < num_r; ++r) {
            dfs(heights, r, num_c - 1);
        }
        for (int c = 0; c < num_c; ++c) {
            dfs(heights, num_r - 1, c);
        }

        vector<vector<int>> ans;
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (reached[r][c] == 2)
                    ans.push_back({r, c});
            }    
        }
        return ans;
    }
    void dfs(const vector<vector<int>>& heights, int r, int c) {
        if (visited[r][c])
            return;
        
        ++reached[r][c];
        visited[r][c] = true;
        int num_r = heights.size();
        int num_c = heights[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if (next_r < 0 || next_c < 0 || next_r >= num_r || next_c >= num_c)
                continue;
            if (heights[next_r][next_c] < heights[r][c])
                continue;
            dfs(heights, next_r, next_c);
        }
    }
};

/* 

 */