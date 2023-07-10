/* 
    透過直接更改 grid value，可以省略 visited 變數，減低 space complexity
 */
class Solution3 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_r = grid.size();
        int num_c = grid[0].size();
        
        int num_island = 0;
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (grid[r][c] == '0') 
                    continue;
                bfs(grid, r, c);
                ++num_island;
            }
        }
        return num_island;
    }
    void bfs(vector<vector<char>> &grid, int r, int c) {
        int num_r = grid.size();
        int num_c = grid[0].size();

        queue<pair<int, int>> que;
        que.push({r, c});

        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!que.empty()) {
            pair<int, int> coord = que.front();
            que.pop();
            int ori_r = coord.first;
            int ori_c = coord.second;
            
            // check four directions
            for (auto dir : dirs) {
                int r = ori_r + dir.first;
                int c = ori_c + dir.second;
                if (r < 0 || c < 0 || r >= num_r || c >= num_c) 
                    continue;
                if (grid[r][c] == '0')
                    continue;
                que.push({r, c});
                grid[r][c] = '0';
            }
        }
    }
};

class Solution2 {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int num_r = grid.size();
    int num_c = grid[0].size();

    vector<vector<bool>> visited;
    visited.resize(num_r, vector<bool>(num_c, false));
    int num_island = 0;
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int r = 0; r < num_r; ++r) {
      for (int c = 0; c < num_c; ++c) {
        if (grid[r][c] == '0' || visited[r][c]) continue;
        queue<pair<int, int>> que;
        que.push({r, c});
        visited[r][c] = true;

        // bfs
        while (!que.empty()) {
          auto coord = que.front();
          que.pop();
          int ori_r = coord.first;
          int ori_c = coord.second;

          // check four directions
          for (auto dir : dirs) {
            int r = ori_r + dir.first;
            int c = ori_c + dir.second;
            if (r < 0 || c < 0 || r >= num_r || c >= num_c) continue;
            if (grid[r][c] == '0' || visited[r][c]) continue;
            que.push({r, c});
            visited[r][c] = true;
          }
        }

        ++num_island;
      }
    }
    return num_island;
  }
};

/*
    TLE
 */
class Solution1 {
 public:
  vector<vector<bool>> visited;
  int numIslands(vector<vector<char>>& grid) {
    int num_r = grid.size();
    int num_c = grid[0].size();

    visited.resize(num_r, vector<bool>(num_c, false));
    int num_island = 0;
    for (int r = 0; r < num_r; ++r) {
      for (int c = 0; c < num_c; ++c) {
        if (grid[r][c] == '0' || visited[r][c]) continue;
        bfs(grid, r, c);
        ++num_island;
      }
    }
    return num_island;
  }
  void bfs(const vector<vector<char>>& grid, int r, int c) {
    if (visited[r][c]) return;
    int num_r = grid.size();
    int num_c = grid[0].size();

    queue<pair<int, int>> que;
    que.push({r, c});

    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!que.empty()) {
      pair<int, int> coord = que.front();
      que.pop();
      int ori_r = coord.first;
      int ori_c = coord.second;
      visited[ori_r][ori_c] = true;

      // check four directions
      /*
          TLE 問題出在這裡，有很多 coord 被重複加入到 que 裡面，因為 coord 加入
         queue 後並沒有馬上更新對應的 visited
       */
      for (auto dir : dirs) {
        int r = ori_r + dir.first;
        int c = ori_c + dir.second;
        if (r < 0 || c < 0 || r >= num_r || c >= num_c) continue;
        if (grid[r][c] == '0' || visited[r][c]) continue;
        que.push({r, c});
      }
    }
  }
};
