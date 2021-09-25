/***** Fourth Visit *****/
class Solution {
public:
    int dirs[4]={1,2,-1,-2};

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='0') continue;
                ans++;
                dfs(grid,i,j,m,n);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return;
        grid[i][j]='0';
        for (int dir:dirs)
            dfs(grid,i+dir/2,j+dir%2,m,n);
    }
};

/***** Third Visit *****/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans=0,m=grid.size(),n=grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='0') continue;
                ans++;
                dfs(grid,i,j,m,n);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(grid,i+1,j,m,n);
        dfs(grid,i-1,j,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i,j-1,m,n);
    }
};

/***** Second Visit *****/
/*
    recurisve traverse each num. If we meet 1, there must be at least one island.
    T:O(4^n)/S:O(n^2)
    -----
    constraint: 1 <= rows, cols <= 300
    Accordance with the constraint, we dont need to worry about TLE.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='0') continue;
                ans++;
                help(grid,m,n,i,j);
            }
        }
        return ans;
    }

    void help(vector<vector<char>>& grid, int m, int n, int i, int j)
    {
        if (i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return;
        grid[i][j]='0';
        help(grid,m,n,i+1,j);
        help(grid,m,n,i-1,j);
        help(grid,m,n,i,j+1);
        help(grid,m,n,i,j-1);
    }
};

/***** First Visit *****/
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
