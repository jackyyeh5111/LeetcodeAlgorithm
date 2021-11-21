/***** Third Visit *****/
/*
    Another approach is that we handle alive cells only.
    1 pass: iterate over the matrix and find the cells alive.
    2 pass: Modify each cell according to the result from 1st pass.
    -----
    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

    1: live
    0: die

    1->1: 2 or 3 neighbors live [1]
    1->0: <2 neighbors live or >3 neighbors die [2]
    0->1: 3 neighbors live [-1]
    0->0 [0]
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m=board.size(), n=board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int lives=0;
                for (int p=-1; p<=1; ++p) {
                    for (int q=-1; q<=1; ++q) {
                        if (i+p<0||i+p>=m||j+q<0||j+q>=n||(p==0&&q==0))
                            continue;
                        lives+=(board[i+p][j+q]>0);
                    }
                }
                if (board[i][j]==0&&lives==3) board[i][j]=-1;
                else if (board[i][j]==1&&(lives==3||lives==2)) board[i][j]=1;
                else if (board[i][j]==1&&(lives<2||lives>3)) board[i][j]=2;
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j]==2) board[i][j]=0;
                else if (board[i][j]==-1) board[i][j]=1;
            }
        }
    }
};

/***** Second Visit *****/
/*
    DO IT SIMULTANEOUSLY
    1->0 if neighbors has less than 2 live [-1]
    1->1 if neighbors has 2 or 3 live [1]
    1->0 if neighbors has more than 3 neighbors [-1]
    0->1 if neighbors has 3 neighbors [2]
    T:O(mn)/S:O(1)
    -----
    Since the board has ints but only the 1-bit is used, we can use the 2-bit to store the new state. At the end, replace the old state with the new state by shifting all values one bit to the right.
*/
class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m=board.size(), n=board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count=0;
                for (int p=i-1; p<=i+1; ++p) {
                    if (p<0||p>=m) continue;
                    for (int q=j-1; q<=j+1; ++q) {
                        if (q<0||q>=n) continue;
                        if (abs(board[p][q])==1) count++;
                    }
                }
                if (board[i][j]==1&&(count-1<2||count-1>3))
                    board[i][j]=-1;
                else if (board[i][j]==0&&count==3) board[i][j]=2;
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j]<0) board[i][j]=0;
                if (board[i][j]==2) board[i][j]=1;
            }
        }
    }
};

/***** First Visit *****/
/*
    in-place updating
    1->0: # of neighbor==1 <2 [-1]
    1->1: # of neighbor==1 == 2 or 3 [1]
    1->0: # of neighbor==1 >3 [-1]
    0->1: # of neighbor==1 ==3 [2]
    T:O(mn)/S:O(1)
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rows=board.size();
        int cols=board[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                int count=0;
                for (int m=i-1; m<i+2; ++m) {
                    if (m<0||m>=rows) continue;
                    for (int n=j-1; n<j+2; ++n) {
                        if (n<0||n>=cols) continue;
                        if (abs(board[m][n])==1) count++;
                    }
                }
                if (board[i][j]==1) {
                    count--;
                    if (count<2||count>3) board[i][j]=-1;
                    else board[i][j]=1;
                }
                else {
                    if (count==3) board[i][j]=2;
                }
            }
        }
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                // cout<<board[i][j]<<",";
                if (board[i][j]==-1) board[i][j]=0;
                if (board[i][j]==2) board[i][j]=1;
            }
            // cout<<endl;
        }
    }
};
