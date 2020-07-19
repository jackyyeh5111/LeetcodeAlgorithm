class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        /*
            back tacking and marked visited entry as a unique value.
            T: O(4*mn)
            ------------
            Simply iterate each entry and check if top&&left is 0 ?
            0 0 0 0
            0 1 0 1
            0 1 1 1
            T: O(2*mn) FAIL with union :(
        */
        if (grid.size()==0) return 0;
        int rows=grid.size(), cols=grid[0].size();
        int count=0;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j]=='1') {
                    help(grid, i, j, rows, cols);
                    count++;
                }
            }
        }
        return count;
    }

    void help(vector<vector<char>>& grid, int i, int j, int rows, int cols)
    {
        if (i<0||i>=rows||j<0||j>=cols) return;
        if (grid[i][j]!='1') return;
        grid[i][j]='x';
        help(grid,i+1,j,rows,cols);
        help(grid,i-1,j,rows,cols);
        help(grid,i,j+1,rows,cols);
        help(grid,i,j-1,rows,cols);
    }
};
