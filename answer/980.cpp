/*
    backtracking
    1. find the location of start point, end point, and obstacles count.
    2. backtracking over all possiblee paths.
    T:O(mn+4^mn)/S:O(mn) due to max depth of recusion.=
*/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        int si=0,sj=0,ei=0,ej=0,num_obstacles=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {si=i; sj=j;}
                if (grid[i][j]==2) {ei=i; ej=j;}
                if (grid[i][j]==-1) num_obstacles++;
            }
        }
        int ans=0,cstep=0, steps=m*n-num_obstacles-2;
        help(grid,si,sj,ei,ej,si-1,sj,cstep,m,n,steps,ans);
        help(grid,si,sj,ei,ej,si+1,sj,cstep,m,n,steps,ans);
        help(grid,si,sj,ei,ej,si,sj-1,cstep,m,n,steps,ans);
        help(grid,si,sj,ei,ej,si,sj+1,cstep,m,n,steps,ans);
        return ans;
    }

    void help(vector<vector<int>>& grid,int si, int sj, int ei, int ej, int ci,
              int cj, int cstep, int m, int n, int steps, int &ans)
    {
        if (ci<0||ci>=m||cj<0||cj>=n||grid[ci][cj]==3||grid[ci][cj]==-1||(si==ci&&sj==cj)) return;
        else if (ci==ei&&cj==ej) { ans+=cstep==steps; return; }
        grid[ci][cj]=3;
        help(grid,si,sj,ei,ej,ci+1,cj,cstep+1,m,n,steps,ans);
        help(grid,si,sj,ei,ej,ci,cj+1,cstep+1,m,n,steps,ans);
        help(grid,si,sj,ei,ej,ci-1,cj,cstep+1,m,n,steps,ans);
        help(grid,si,sj,ei,ej,ci,cj-1,cstep+1,m,n,steps,ans);
        grid[ci][cj]=0;
    }
};
