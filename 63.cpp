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
