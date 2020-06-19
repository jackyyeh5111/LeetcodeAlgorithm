class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        /*
        first thought: scan from top left to right end, each time we found O,
        start tracinig neigborhood.
        We can have flags of O, non visit:0, visited:1

        improve thought, tracing only on the boardingi of border, the rest of O internal could be
        teat as X.
        */
        // T:O(mn)
        if (board.size()==0 || board[0].size()==0) return;
        int rows=board.size(); int cols=board[0].size();
        for (int row=0; row<rows; ++row) {
            dfs(board,row,0,rows,cols);
            dfs(board,row,cols-1,rows,cols);
        }
        for (int col=1; col<cols-1; ++col) {
            dfs(board,0,col,rows,cols);
            dfs(board,rows-1,col,rows,cols);
        }
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (board[i][j]=='O') board[i][j]='X';
                if (board[i][j]=='1') board[i][j]='O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y, int rows, int cols)
    {
        if (board[x][y]=='O') {
            // cout<<x<<","<<y<<endl;
            board[x][y]='1';
            if (y+1<cols) dfs(board, x,y+1,rows,cols);
            if (y-1>=0) dfs(board, x,y-1,rows,cols);
            if (x+1<rows) dfs(board, x+1,y,rows,cols);
            if (x-1>=0) dfs(board, x-1,y,rows,cols);
        }
    }
};
