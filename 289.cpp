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
