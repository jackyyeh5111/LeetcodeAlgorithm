class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        // back tracking
        // T:O(n^2)tracking*O(n)feasible, T:O(n^3)
        // S:O(1)
        // note: checking could be replaced with a global hashtable
        // Then T: O(n^2), S:(n)
        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j)
    {
        if (i==9) return true;
        if (j==9) return solveSudoku(board, i+1, 0);
        if (board[i][j]!='.') return solveSudoku(board, i, j+1);

        for (int c=0; c<9; ++c) {
            char val = '1' + c;
            if (feasible(board, i, j, val)) {
                board[i][j] = val;
                if (solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool feasible(vector<vector<char>>& board, int i, int j, char val)
    {
        int row=i/3*3; int col=j/3*3;
        for(int x=0; x<9; ++x) {
            if (board[x][j]==val||board[i][x]==val||
                board[row+x/3][col+x%3]==val) return false;
        }

        return true;
    }
};
