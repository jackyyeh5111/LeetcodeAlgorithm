class NumMatrix {
public:
    vector<vector<int>> matrix;
    int m=0,n=0;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        if (m>0) n=matrix[0].size();
        for (int j=1; j<n; ++j)
            matrix[0][j]+=matrix[0][j-1];
        for (int i=1; i<m; ++i)
            matrix[i][0]+=matrix[i-1][0];
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j)
                matrix[i][j]+=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
        }
        this->matrix=matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m==0&&n==0) return 0;
        int ans=matrix[row2][col2];
        if (row1-1>=0&&col1-1>=0)
            ans+=(matrix[row1-1][col1-1]-matrix[row1-1][col2]-matrix[row2][col1-1]);
        else if (col1-1>=0) ans-=matrix[row2][col1-1];
        else if (row1-1>=0) ans-=matrix[row1-1][col2];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
