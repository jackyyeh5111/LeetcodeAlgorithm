/***** Second Visit *****/
/*
    top-down recursive (row-major)
    T:O(9^4)/S:O(9^2) recursive depth
    -----
    use global bool table with size 9,9 to check if exist
    rows[9][9]: 9 rows, 9 value
    cols[9][9]: 9 cols, 9 value
    blocks[9][9]: 9 blocks, 9 value
    then checking time complexity could reduce to O(1)
    T:O(9^3)/S:O(9^2) recursive depth
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        help(board,0,0);
    }

    bool help(vector<vector<char>>& board, int row, int col)
    {
        if (row==8&&col==9) return true;
        else if (col==9) return help(board,row+1,0);
        else if (board[row][col]!='.') return help(board,row,col+1);
        for (int i=0; i<9; ++i) {
            if (feasible(board,row,col,i)) {
                // cout<<"row"<<row<<"col"<<col<<"val"<<i+1<<endl;
                board[row][col]='1'+i;
                if (help(board,row,col+1)) return true;
                else board[row][col]='.';
            }
        }
        return false;
    }

    bool feasible(vector<vector<char>>& board, int row, int col, int val)
    {
        for (int i=0; i<9; ++i) {
            if (board[i][col]=='1'+val) return false;
            if (board[row][i]=='1'+val) return false;
            if (board[row/3*3+i/3][col/3*3+i%3]=='1'+val) return false;
        }
        return true;
    }
};

/***** First visit *****/
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
