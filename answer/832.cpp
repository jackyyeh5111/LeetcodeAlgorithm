/*
    0 1 2 3 / 4
    0 1 2 3 4 / 5
    T:O(mn)/S:O(1)
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        int m=A.size(),n=A[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<(n+1)/2; ++j) {
                swap(A[i][j],A[i][n-j-1]);
                A[i][j]=1-A[i][j];
                if (j!=n-j-1) A[i][n-j-1]=1-A[i][n-j-1];
            }
        }
        return A;
    }
};
