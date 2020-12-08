/***** Second Visit *****/
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n,string(n,'.'));
        help(board,0,0,n);
        return ans;
    }

    void help(vector<string> &board, int i, int j, int n)
    {
        // cout<<i<<","<<j<<endl;
        // for (auto s:board) cout<<s<<endl;
        // cout<<"---"<<endl;
        if (i>=n) return;
        else if (j>=n) {ans.push_back(board); return;}
        if (feasible(board,i,j,n)) {
            board[i][j]='Q';
            help(board,0,j+1,n);
            board[i][j]='.';
        }
        help(board,i+1,j,n);
    }

    bool feasible(vector<string> &board, int i, int j, int n)
    {
        for (int k=0; k<n; ++k) {
            if (board[k][j]=='Q'||board[i][k]=='Q') return false;
        }
        for (int k=j; k>=0; --k) {
            if (i-j+k>=0&&board[i-j+k][k]=='Q') return false;
            if (i+j-k<n&&board[i+j-k][k]=='Q') return false;
        }
        return true;
    }
};

/***** First Visit *****/
/************* Recursive Arrproach *************/
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

/************* Iteration via Stack Arrproach *************/
/***********************************************/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        // back tracking
        vector<string> table(n,string(n,'.'));
        vector<vector<bool>> tracked(n,vector<bool>(n,false));
        vector<vector<string>> ans;
        stack<pair<int,int>> s;
        for (int i=n-1; i>=0; --i)
            s.push(make_pair(i,0));
        while (!s.empty()) {
            auto top = s.top();
            int row=top.first; int col=top.second;
            if (tracked[row][col]) {
                table[row][col]='.';
                tracked[row][col]=false;
                s.pop();
                continue;
            }

            bool feasible=true;
            for (int i=0; i<n; ++i) {
                if ((table[row][i]=='Q'&&i!=col) ||
                    (table[i][col]=='Q'&&i!=row) )
                    feasible=false;
            }
            for (int i=col-1; i>=0; --i){
                if ((row-col+i>=0&&table[row-col+i][i]=='Q') ||
                    (row+col-i<n&&table[row+col-i][i]=='Q') )
                    feasible=false;
            }
            if (feasible){
                table[row][col]='Q';
                tracked[row][col]=true;
                if (col==n-1) {
                    ans.push_back(table);
                    table[row][col]='.';
                    tracked[row][col]=false;
                    s.pop();
                    cout<<"find"<<endl;
                }
                for (int i=0; i<n; ++i){
                    if (col<n-1)
                        s.push(make_pair(i,col+1));
                }
            }
            else
                s.pop();
        }
        return ans;
    }
};
