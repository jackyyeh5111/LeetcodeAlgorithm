#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool dfs(const vector<vector<int>> &board, int row, int col, vector<pair<int, int>> &completed, vector<vector<int>> &visited) {
    int num_r = board.size();
    int num_c = board[0].size();
    if (visited[row][col] == 1) return true; // visiting
    else if (visited[row][col] == 2) return false; // not surrounded by 1
    
    visited[row][col] = 1;
    completed.emplace_back(row, col);
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (const auto&[dir_r, dir_c] : dirs) {
        int next_r = row + dir_r;
        int next_c = col + dir_c;
        // boundary check
        if (next_r < 0 || next_r >= num_r || next_c < 0 || next_c >= num_c)
            continue;
        
        if (board[next_r][next_c] == 0) return false;
        // else if (board[next_r][next_c] == 1) not need to do anything

        if (board[next_r][next_c] == 2) {
            // visit next coord
            if (!dfs(board, next_r, next_c, completed, visited)) {
                visited[row][col] = 2;
                return false;
            }
        }
    }
    return true;
}

void goBoard(vector<vector<int>> &board) {
    int num_r = board.size();
    int num_c = board[0].size();
    vector<vector<int>> visited(num_r, vector<int>(num_c));
    for (int r = 0; r < num_r; r++) {
        for (int c = 0; c < num_c; c++) {
            if (visited[r][c] != 0 || board[r][c] != 2)
                continue;

            // 1) dfs
            vector<pair<int, int>> completed;
            if (!dfs(board, r, c, completed, visited))
                continue;

            // 2) update board
            for (const auto& [row, col] : completed)
                board[row][col] = 0;
        }
    }
}

/* 
  status only goes to coord with value 2.
    status = 0 // not visited
    status = 1 // visiting
    status = 2 // visited, and not surrounding by 1
    status = 3 // visited, and surrounding by 1 (not needed, because we modify 2 to zero every iteration)
 */
int main() {
    // Example board
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 2, 1, 1, 1},
        {0, 1, 2, 1, 2, 2},
        {0, 1, 2, 2, 1, 2}
    };

    goBoard(board);

    // Print updated board
    cout << "\nfinal board:\n";
    for (const auto &row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
