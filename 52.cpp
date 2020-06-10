class Solution {
public:
    int count = 0;
    vector<bool> angle45;
    vector<bool> angle135;
    vector<bool> angle0;

    // T:O(n!), n x n-1 x n-2 x n-3 x ... x 1
    // S:O(n)
    int totalNQueens(int n)
    {
        angle45 = vector<bool>(2*n-1,0);
        angle135 = vector<bool>(2*n-1,0);
        angle0 = vector<bool>(n,0);
        backtracking(0, n);
        return count;
    }

    void backtracking(int row, int n)
    {
        if (row==n) count++;
        for (int col=0; col<n; ++col) {
            int idx45 = row+col;
            int idx135 = n-1+col-row;
            if (angle0[col] ||angle45[idx45]||angle135[idx135])continue;

            angle0[col]=true; angle45[idx45]=true; angle135[idx135]=true;
            backtracking(row+1, n);
            angle0[col]=false; angle45[idx45]=false; angle135[idx135]=false;
        }
    }
};
