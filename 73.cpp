/****************** S:O(1) ******************/
/*
store states of each row in the first of that row, and store states of each column in the first of that column. Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. In the first phase, use matrix elements to set states in a top-down way. In the second phase, use states to set matrix elements in a bottom-up way.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        // brute force: T:O(mn), S:O(m+n)
        // If we'd like to have constant space:
        // 1. we can find a flag to represent true 0.
        // 2. Save flag somewhere.

        int col0=1; int rows=matrix.size(), cols=matrix[0].size();
        for (int i=0; i<rows; ++i) {
            if (matrix[i][0]==0) col0=0;
            for (int j=1; j<cols; ++j) {
                if (matrix[i][j]==0) {
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }

        for (int i=rows-1; i>=0; --i) {
            for (int j=cols-1; j>0; --j) {
                if (matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if (col0==0) matrix[i][0]=0;
        }
    }
};

/****************** S:O(m+n) ******************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        // brute force: T:O(mn), S:O(m+n)
        vector<vector<int>> record;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j]==0)record.push_back(vector<int>{i,j});
            }
        }

        for (auto p:record){
            for (int x=0; x<matrix.size(); ++x) matrix[x][p[1]]=0;
            for (int x=0; x<matrix[0].size(); ++x) matrix[p[0]][x]=0;
        }
    }
};
