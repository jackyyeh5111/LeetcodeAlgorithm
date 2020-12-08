/***** Second Visit *****/
/*
    Actually we dont need to specific use sign bit to check if visited or not,
    T:O(mn)/S:O(1) in-place
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int val=-1;
        for(int i=0; i<m; ++i) {
            if (obstacleGrid[i][0]==1) val=0;
            obstacleGrid[i][0]=val;
        }
        val=-1;
        for(int i=0; i<n; ++i) {
            if (obstacleGrid[0][0]==0||obstacleGrid[0][i]==1) val=0;
            obstacleGrid[0][i]=val;
        }
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (obstacleGrid[i][j]==1) obstacleGrid[i][j]=0;
                else {
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1]*-1;
    }
};

/***** First Visit *****/
/*
DP Solution
Note the paths turns out to be 0 if we meet obstacle
*/
class Solution {
public:
    // T:O(mn), S:O(n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> table(obstacleGrid[0].size(),0);
        for (int i=0; i<obstacleGrid[0].size(); ++i) {
            if(obstacleGrid[0][i]==0) table[i]=1;
            else break;
        }
        int reachable=obstacleGrid[0][0]!=1;
        for (int i=1; i<obstacleGrid.size(); ++i){
            for (int j=0; j<obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j]==1) {
                    table[j]=0;
                    if (j==0) reachable=0;
                }
                else if (j==0) table[j]=reachable;
                else table[j]+=table[j-1];
            }
        }
        return table[obstacleGrid[0].size()-1];
    }
};
