#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool dfs(vector<vector<int>> &board, int cur_row, int cur_col, vector<pair<int, int>> &completed, vector<vector<int>> &visited) {
    int n_row = board.size();
    int n_col = board[0].size();

    // If out of bounds or already visited, skip
    if (visited[cur_row][cur_col] == 1) return true;
    else if (visited[cur_row][cur_col] == 2) {
      visited[cur_row][cur_col] = 2;
      return false;
    }

    // Mark as visited
    visited[cur_row][cur_col] = 1; // visiting

    // Add current cell to the completed list
    completed.emplace_back(cur_row, cur_col);

    // Directions: right, down, left, up
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool should_modified = true;
    for (const auto &dir : dirs) {
        int next_row = cur_row + dir[0];
        int next_col = cur_col + dir[1];

        // check boundary
        if (next_row < 0 || next_row >= n_row || next_col < 0 || next_col >= n_col)
          continue;
        if (board[next_row][next_col] == 0) {
          should_modified = false;
        }
        // else if (board[next_row][next_col] == 1) // do nothing
        else if (board[next_row][next_col] == 2) {
            if (!dfs(board, next_row, next_col, completed, visited)) {
              should_modified = false;
              break;
            }
        }
    }
    if (should_modified) return true;
    
    visited[cur_row][cur_col] = 2; // visited, not surrounded by 1
    return false;
}

void goBoard(vector<vector<int>> &board) {
    int n_row = board.size();
    int n_col = board[0].size();

    // Track visited cells
    vector<vector<int>> visited(n_row, vector<int>(n_col));

    for (int r = 0; r < n_row; r++) {
        for (int c = 0; c < n_col; c++) {
            if (board[r][c] != 2 || visited[r][c] != 0) 
              continue;
            
            // dfs
            vector<pair<int, int>> completed;
            if (dfs(board, r, c, completed, visited)) {
                // Modify surrounded components
                for (const auto &[row, col] : completed) {
                    board[row][col] = 0;
                }
            }
        }
    }

    // Print updated board
    cout << "visited matrix:\n";
    for (const auto &row : visited) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
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
        {0, 1, 2, 1, 1, 0},
        {0, 1, 2, 1, 2, 1},
        {0, 1, 2, 2, 1, 0}
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
