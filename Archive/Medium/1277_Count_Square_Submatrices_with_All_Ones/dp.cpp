class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int x_total = matrix.size();
        int y_total = matrix[0].size();
        vector<vector<int>> acc;
        for (int x=0; x<x_total; ++x)
            acc.push_back(vector<int>(y_total, 0));

        for (int x=0; x<x_total; ++x) {
            for (int y=0; y<y_total; ++y) {
                if (matrix[x][y] == 0) acc[x][y] = 0;
                else {
                    if (x==0 || y==0)
                        acc[x][y] = 1;
                    else
                        acc[x][y] = 1 + min({acc[x-1][y],
                                             acc[x][y-1],
                                             acc[x-1][y-1]});
                }
            }
        }

        int result = 0;
        for (int x=0; x<x_total; ++x) {
            for (int y=0; y<y_total; ++y) {
                result += acc[x][y];
            }
        }
        return result;
    }
};
/* 2-d Induction
dp[i][j] represent length of the biggest square whose lower right corner element is matrix[i][j]. Also there are dp[i][j] squares whose lower right corner element are matrix[i][j]. The answer of count-square-submatrices-with-all-ones is sum of all dp[i][j].

As Figure, the square edge length ( whose lower right corner element is matrix[i][j] ) is not greater than the minium of three arrows + 1.

Fortunately it can be equal to when matrix[i][j]==1. On this condition dp[i][j]=the minium of three arrows + 1;

And when matrix[i][j]==0 , dp[i][j]=0.
*/
