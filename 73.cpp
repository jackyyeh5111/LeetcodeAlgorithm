/***** Third Visit *****/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix.size(),n=matrix[0].size();
        bool hor=false,ver=false;
        for (int i=0; i<m; ++i) ver|=matrix[i][0]==0;
        for (int i=0; i<n; ++i) hor|=matrix[0][i]==0;
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for (int i=1; i<m; ++i) {
            if (matrix[i][0]==0) {
                int j=0;
                while (j<n) matrix[i][j++]=0;
            }
            if (ver) matrix[i][0]=0;
        }
        for (int i=1; i<n; ++i) {
            if (matrix[0][i]==0) {
                int j=0;
                while (j<m) matrix[j++][i]=0;
            }
            if (hor) matrix[0][i]=0;
        }
        if (hor||ver) matrix[0][0]=0;
    }
};

/***** Second Visit (Fail) *****/
/*
    zero out rows/cols with constant space.
    use a vector to store the position of each zero, then zero out.
    T:O(mn)/S:O(mn)
    -----
    try to use a delimeter? no way, each num has range INT_MIN to INT_MAX.
    -----
    check row/col for each entry over right/down part.
    T:O(mn*(m+n))/S:O(1)
    COULD NOT HANDLE true 0 v.s. false 0.
    -----
    store 0 state in first row/col. since matrix[0][0] have to store both row's/col's states,
    we use another var to store the state of col0 and let matrix[0][0] store the state of row0.
    T:O(mn)/S:O(1)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix.size(), n=matrix[0].size(),col0=1;
        for (int i=0; i<m; ++i) {
            if (matrix[i][0]==0) col0=0;
            for (int j=1; j<n; ++j) {
                if (matrix[i][j]==0) matrix[i][0]=matrix[0][j]=0;
            }
        }

        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>0; --j) {
                if (matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
            }
            if (col0==0) matrix[i][0]=0;
        }
    }
};

/***** First Visit *****/
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
