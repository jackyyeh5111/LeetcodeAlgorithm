/*
     Wrong ansewr!
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int num_r = board.size();
        int num_c = board[0].size();

        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (word[0] != board[r][c]) 
                    continue;
                if (bfs(board, r, c, word))
                    return true;
            }
        }

        return false;
    }
    bool bfs(const vector<vector<char>>& board, int r, int c, string word) {
        int num_r = board.size();
        int num_c = board[0].size();
        vector<vector<bool>> visited(num_r, vector<bool>(num_c));

        vector<vector<int>>dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<vector<int>> que;
        que.push({r, c});
        int idx = 0;
        while(!que.empty()) {
            vector<int> coord = que.front();
            que.pop();
            int raw_r = coord[0];
            int raw_c = coord[1];
            if (visited[raw_r][raw_c])
                continue;
            visited[raw_r][raw_c] = true;

            ++idx;
            for (auto dir : dirs) {
                int r = raw_r + dir[0];
                int c = raw_c + dir[1];
                if (visited[r][c])
                    continue;
                if (r < 0 || c < 0 || r >= num_r || c >= num_c)
                    continue;
                if (board[r][c] == word[idx]) {
                    if (idx == word.size() - 1)
                        return true;
                    que.push({r, c});
                }
            }
        }
        return false;
    }
};



