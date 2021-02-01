/*
    DP T:O(n^2)
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[i][j]==0) continue;
                matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
                ans+=matrix[i][j];
            }
        }
        for (int i=0; i<m; ++i) ans+=matrix[i][0];
        for (int i=1; i<n; ++i) ans+=matrix[0][i];
        return ans;
    }
};
