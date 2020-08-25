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
