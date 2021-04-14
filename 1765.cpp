/*
    In DFS, it costs T:O(mn) for each water land. Lets say we have k water lands, then it probably costs T:O(mnk)
    In BFS, we walk from each water land in parallel. It only takes one traverse time T:O(mn)
    -----
    dfs
    T:O(mn*4*k)
    -----
    bfs
    T:O(mn*4)
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m=isWater.size(), n=isWater[0].size();
        queue<pair<int,int>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isWater[i][j]==1) {
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=INT_MAX;
            }
        }
        int h=0;
        while(!q.empty()) {
            int k=q.size();
            while(k--) {
                auto p=q.front(); q.pop();
                int x=p.first, y=p.second;
                if (x<0||x>=m||y<0||y>=n||(h>=isWater[x][y]&&h!=0)) continue;
                isWater[x][y]=h;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
            h++;
        }
        return isWater;
    }

};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m=isWater.size(), n=isWater[0].size();
        vector<vector<int>> waters;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isWater[i][j]==1) {
                    waters.push_back({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=INT_MAX;
            }
        }
        for (auto w:waters)
            dfs(isWater,w[0],w[1],0);
        return isWater;
    }

    void dfs(vector<vector<int>>& isWater, int i, int j, int h)
    {
        int m=isWater.size(), n=isWater[0].size();
        if (i<0||i>=m||j<0||j>=n||(h>=isWater[i][j]&&h!=0)) return;
        isWater[i][j]=h;
        dfs(isWater,i+1,j,h+1);
        dfs(isWater,i-1,j,h+1);
        dfs(isWater,i,j+1,h+1);
        dfs(isWater,i,j-1,h+1);
    }
};
