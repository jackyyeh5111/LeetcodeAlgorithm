class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // Same idea with prob.63
        // 1-d DP solution
        vector<int> table(grid[0].size(), 0);
        table[0]=grid[0][0];
        for (int i=1; i<grid[0].size(); ++i){ table[i]=table[i-1]+grid[0][i]; }
        for (int i=1; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (j==0) table[0]+=grid[i][0];
                else table[j]=min(table[j-1], table[j])+grid[i][j];
            }
        }
        return table[grid[0].size()-1];

    }
};
