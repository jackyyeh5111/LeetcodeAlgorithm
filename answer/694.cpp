/*
    Our goal is to first reduce the duplicate island, then do DFS for island ocunting
    How to reduce dupliate!? Try encode way
    For any island, think about island encoding ways:
    1: record its coord in sorted order, and check all offset.
    2: bitset? Make comparison time cost T:O(2500)->T:O(1)
       However, we should take care row major and col major both.
    3: Directly use string encoding in terms of direction up/down/left,right.
*/

// method 2, bitset encoding
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid)
    {
        unordered_set<bitset<2500>> seen_hz, seen_vt;
        int m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                bitset<2500> cur_hz, cur_vt;
                dfs(grid,i,j,cur_hz, cur_vt);
                if (cur_hz.count()==0) continue;
                int k=0;
                while(!cur_hz.test(k)) k++;
                cur_hz=cur_hz>>k;
                k=0;
                while(!cur_vt.test(k)) k++;
                cur_vt=cur_vt>>k;
                if (seen_hz.count(cur_hz)==0) seen_hz.insert(cur_hz);
                if (seen_vt.count(cur_vt)==0) seen_vt.insert(cur_vt);
            }
        }

        return max(seen_hz.size(),seen_vt.size());
    }

    void dfs(vector<vector<int>> &grid, int x, int y,
             bitset<2500> &cur_hz, bitset<2500> &cur_vt)
    {
        int m=grid.size(), n=grid[0].size();
        if (x<0||x>=m||y<0||y>=n||grid[x][y]==0) return;
        grid[x][y]=0;
        cur_hz.set(x*m+y);
        cur_vt.set(y*n+x);
        dfs(grid,x+1,y,cur_hz,cur_vt);
        dfs(grid,x-1,y,cur_hz,cur_vt);
        dfs(grid,x,y+1,cur_hz,cur_vt);
        dfs(grid,x,y-1,cur_hz,cur_vt);
    }
};

// method 3, string direction encoding.
class Solution {
    int M = 0;
    int N = 0;

    void explore(vector<vector<int>>& grid, int i, int j, string& path,
                 char dir) {
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) {
            path.push_back('f'); // this attempt failed
            return;
        }
        grid[i][j] = 0;
        path.push_back(dir);
        explore(grid, i-1, j, path, 'u'); // up
        explore(grid, i+1, j, path, 'd'); // down
        explore(grid, i, j-1, path, 'l'); // left
        explore(grid, i, j+1, path, 'r'); // right
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        unordered_set<string> islands;
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    string path;
                    explore(grid, i, j, path, 'o'); // 'o' for origin
                    islands.insert(path);
                }
            }
        }
        return islands.size();;
    }
};
