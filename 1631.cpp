/*
    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    dp[i][j] min effort so far from top left to i,j.
    dp[i][j]=min(max(dp[i-1][j],abs(heights[i][j]-heights[i-1][j])),
                 max(dp[i][j-1],abs(heights[i][j]-heights[i][j-1])))
    Note: You can move up, down, left, or right,
    DP approach could only satisfy going right/down.
    -----
    backtracking
    T:O(2^(mn)) -> TLE
    -----
    DFS to search min possible effort
    DFS:O(mn), times: O(log100000)
    -----
    Dijastra
    T:O(mnlog(mn))
*/

// Dijastra
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> diff(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        auto compare=[](auto a, auto b){return a[2]>b[2];};
        // <x,y,diff>
        priority_queue<vector<int>,vector<vector<int>>,decltype(compare)> pq(compare);
        diff[0][0]=0;
        pq.push({0,0,diff[0][0]});
        while (!pq.empty()) {
            auto t=pq.top(); pq.pop();
            visited[t[0]][t[1]]=1;
            if (t[0]==m-1&&t[1]==n-1) return t[2];
            for (auto dir:dirs) {
                int x=t[0]+dir[0],y=t[1]+dir[1];
                if (checkXY(x,y,m,n)&&!visited[x][y]) {
                    int curDiff=abs(heights[x][y]-heights[t[0]][t[1]]);
                    int maxDiff=max(curDiff,diff[t[0]][t[1]]);
                    if (maxDiff<diff[x][y]) {
                        diff[x][y]=maxDiff;
                        pq.push({x,y,maxDiff});
                    }
                }
            }
        }

        return diff[m-1][n-1];
    }

    bool checkXY(int x, int y, int m, int n)
    {
        return x>=0&&x<m&&y>=0&&y<n;
    }
};

// binary search on effort to find out min effort to reach the tgt.
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (dfsUtil(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfsUtil(vector<vector<int>> &heights, int mid) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        return canReachDestinaton(0, 0, heights, visited, row, col, mid);
    }

    bool canReachDestinaton(int x, int y, vector<vector<int>> &heights,
                            vector<vector<bool>> &visited, int row, int col,
                            int mid) {
        if (x == row - 1 && y == col - 1) {
            return true;
        }
        visited[x][y] = true;
        for (auto direction : directions) {
            int adjacentX = x + direction[0];
            int adjacentY = y + direction[1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                !visited[adjacentX][adjacentY]) {
                int currentDifference =
                    abs(heights[adjacentX][adjacentY] - heights[x][y]);
                if (currentDifference <= mid) {
                    if (canReachDestinaton(adjacentX, adjacentY, heights,
                                           visited, row, col, mid))
                        return true;
                }
            }
        }
        return false;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};
