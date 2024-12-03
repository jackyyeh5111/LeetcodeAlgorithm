#include <iostream>
using namespace std;

// Given a go board
// e.g.
// 0 0 0 0 0 0
// 0 0 1 0 0 0
// 0 1 2 1 0 0
// 0 1 2 1 0 0
// 0 1 2 1 0 0

queue<pair<int, int>> {
}

vector<pair<int, int>> { // completed coord
  {2,2},
  {3,2},
  {4, 2}
}
// 1 2 2
// 2 2 2
// 2 2 2

// remove the surrounded 2s
bool dfs(vector<vector<int>> &board, int cur_row, int cur_col, vector<pair<int, int>>& completed, vector<vector<bool>> &visited) {
  
  if (visited[cur_row][cur_col]) return true;
  visited[cur_row][cur_col] = true;

  int n_row = board.size();
  int n_col = board[0].size();

  // four directions
  vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  completed.push_back({cur_row, cur_col});

  // check four directions
  for (const auto & dir : dirs) {
    int next_row = cur_row + dir[0];
    int next_col = cur_col + dir[1];
    
    if (next_row < 0 || next_row >= n_row || next_col < 0 || next_col >= n_col)
      continue;
    if (board[next_row][next_col] == 0)
      return false;
    // if (board[next_row][next_col] == 1)  // not need to do anything
    
    if (board[next_row][next_col] == 2) {
      bool should_modified = dfs(board, next_row, next_col, completed, visited);
      if (!should_modified)
        return false;
    }
  }
  return true;
}

void goBoard(vector<vector<int>> &board) {
  int n_row = board.size();
  int n_col = board[0].size();
  
  vector<vector<bool>> visited(n_row, vector<bool>(n_col));
  for (int r = 0; r < n_row; r++) {
    for (int c = 0; c < n_col; c++) {
      if (board[r][c] == 2) {
        vector<pair<int, int>> completed;
        bool should_modified = dfs(board, r, c, completed, visited);
        if (should_modified) {
          // TODO
          // remove two to zero based on completed
          for (const auto& [row, col] : completed) {
            board[row][col] = 0;
          }
        }
      }
    }
  }
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const char* const& word : words) {
    cout << word;
  }
  return 0;
}
