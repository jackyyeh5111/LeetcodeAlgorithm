/*
    the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is
    no obstacle on the new lane.

    Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

    n+1 points with length n, 3 lan
    dp[i][j] denotes the min number of side jump, i:position, j: lane
    size: n+1 x 3
    return min(dp[n][0],dp[n][1],dp[n,2])

    induction: dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1,dp[i-1][j+1]+1) iff cur node is not obstacle.
    T:O(n*k), k denotes the # of lanes.
*/
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(3,0)); // n x 3
        dp[0][0]=1; dp[0][1]=0; dp[0][2]=1;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<3; ++j) {
                if (obstacles[i]-1==j) dp[i][j]=INT_MAX;
                else {
                    dp[i][j]=INT_MAX;
                    if (dp[i-1][0]!=INT_MAX&&obstacles[i]-1!=0)
                        dp[i][j]=min(dp[i][j],dp[i-1][0]+(j!=0));
                    if (dp[i-1][1]!=INT_MAX&&obstacles[i]-1!=1)
                        dp[i][j]=min(dp[i][j],dp[i-1][1]+(j!=1));
                    if (dp[i-1][2]!=INT_MAX&&obstacles[i]-1!=2)
                        dp[i][j]=min(dp[i][j],dp[i-1][2]+(j!=2));
                }
            }
        }
        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};
