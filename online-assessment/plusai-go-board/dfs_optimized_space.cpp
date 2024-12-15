#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void printBoard(const vector<vector<int>> &board) {
    for (const auto &row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

/* 
    board = 2 // visiting
    board = 3 // visiting
    board = 4 // visited, and not surrounding by 1
 */
void dfs(vector<vector<int>> &board, int row, int col) {
    int num_r = board.size();
    int num_c = board[0].size();
    if (board[row][col] == 3) return; // visiting
    else if (board[row][col] == 4) return; // not surrounded by 1
    
    board[row][col] = 3;
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (const auto&[dir_r, dir_c] : dirs) {
        int next_r = row + dir_r;
        int next_c = col + dir_c;
        // boundary check
        if (next_r < 0 || next_r >= num_r || next_c < 0 || next_c >= num_c)
            continue;
        
        if (board[next_r][next_c] == 0 || board[next_r][next_c] == 4) {
            board[row][col] = 4;
            return;
        }
        // else if (board[next_r][next_c] == 1) not need to do anything
        // else if (board[next_r][next_c] == 3) visiting
        
        // visit next coord
        if (board[next_r][next_c] == 2) {
            dfs(board, next_r, next_c);
            if (board[next_r][next_c] == 4) {
                board[row][col] = 4; // back propogate
                return;
            }
        }
    }
}

void goBoard(vector<vector<int>> &board) {
    int num_r = board.size();
    int num_c = board[0].size();
    vector<vector<int>> visited(num_r, vector<int>(num_c));
    for (int r = 0; r < num_r; r++) {
        for (int c = 0; c < num_c; c++) {
            if (visited[r][c] != 0 || board[r][c] != 2)
                continue;
            dfs(board, r, c);
        }
    }

    cout << "middle board:\n";
    printBoard(board);

    // 2) update board
    for (int r = 0; r < num_r; r++) {
        for (int c = 0; c < num_c; c++) {
            if (board[r][c] == 3) board[r][c] = 0;
            else if (board[r][c] == 4) board[r][c] = 2;
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
        {0, 1, 2, 2, 1, 0}
    };

    goBoard(board);

    // Print updated board
    cout << "\nfinal board:\n";
    printBoard(board);
    return 0;
}
