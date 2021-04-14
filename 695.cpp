class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size()==0||grid[0].size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int cur=0;
                dfs(grid,i,j,cur,ans);
            }
        }
        return ans;
     }

    void dfs(vector<vector<int>>& grid, int i, int j, int &cur, int &ans)
    {
        int m=grid.size(), n=grid[0].size();
        if (i<0||i>=m|j<0||j>=n||grid[i][j]==0) return;
        grid[i][j]=0;
        cur++;
        ans=max(ans,cur);
        dfs(grid,i+1,j,cur,ans);
        dfs(grid,i-1,j,cur,ans);
        dfs(grid,i,j+1,cur,ans);
        dfs(grid,i,j-1,cur,ans);
    }
};
