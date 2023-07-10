/* 
    Time Limit exceed
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int num_r = board.size();
        int num_c = board[0].size();

        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                vector<vector<bool>> visited(num_r, vector<bool>(num_c));
                if (dfs(board, r, c, word, 0, visited))
                    return true;
            }
        }

        return false;
    }
    bool dfs(const vector<vector<char>>& board, int r, int c, string word, int idx, vector<vector<bool>> visited) {
        if (word[idx] != board[r][c])
            return false;
        if (idx == word.size() - 1)
            return true;
        
        visited[r][c] = true;
        int num_r = board.size();
        int num_c = board[0].size();

        vector<vector<int>>dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : dirs) {
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if (next_r < 0 || next_c < 0 || next_r >= num_r || next_c >= num_c)
                continue;
            if (visited[next_r][next_c])
                continue;
            if (dfs(board, next_r, next_c, word, idx + 1, visited))
                return true;
        }
        return false;
    }
};



