class Solution {
public:
    vector<vector<int>> reached;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_r = heights.size();
        int num_c = heights[0].size();
        reached.resize(num_r, vector<int>(num_c));
        
        queue<vector<int>> queP;
        queue<vector<int>> queA;
        for (int r=0; r < num_r; ++r) {
            queP.push({r, 0});
            queA.push({r, num_c - 1});
        }
        for (int c=0; c < num_c; ++c) {
            queP.push({0, c});
            queA.push({num_r - 1, c});
        }
        bfs(heights, queP);
        bfs(heights, queA);

        vector<vector<int>> ans;
        for (int r=0; r < num_r; ++r) {
            for (int c=0; c < num_c; ++c) {
                if (reached[r][c] == 2)
                    ans.push_back({r, c});
            }
        }
        return ans;
    }
    void bfs(const vector<vector<int>> &heights, queue<vector<int>> &que) {
        int num_r = heights.size();
        int num_c = heights[0].size();
        vector<vector<bool>> visited(num_r, vector<bool>(num_c));

        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!que.empty()) {
            vector<int> coord = que.front();
            que.pop();
            int raw_r = coord[0];
            int raw_c = coord[1];
            if (visited[raw_r][raw_c]) // do not forget this.
                continue;

            visited[raw_r][raw_c] = true;
            ++reached[raw_r][raw_c];

            for (auto dir : dirs) {
                int r = raw_r + dir[0];
                int c = raw_c + dir[1];
                if (r < 0 || c < 0 || r >= num_r || c >= num_c)
                    continue;
                if (visited[r][c] || heights[r][c] < heights[raw_r][raw_c])
                    continue;
                que.push({r, c});
            }
            
        }
    }
};





