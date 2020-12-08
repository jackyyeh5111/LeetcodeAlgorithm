/***** Third Visit *****/
/*
    bottom-up 2-d DP would be a bad idea since we not only need to find the max remaining health in each dungeon but also need to take care if current health is down to 0 or lower. Or even calculate current MAX rest health with magic orb.

    However, if we start from pricess's dungeon, we don't need to handle the current maximum remain health. Just focus on insufficient health.
    dp[i][j] denotes the min needed health to reach pricess start from (i,j)
    T:O(mn)/S:O(m+n)
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<int> dp(n+1,0); dp[n]=INT_MIN;
        dp[n-1]=dungeon[m-1][n-1]>0?0:dungeon[m-1][n-1];
        for (int j=n-2; j>=0; --j) {
            dp[j]=min(0,dp[j+1]+dungeon[m-1][j]);
        }
        for (int i=m-2; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                dp[j]=max(dp[j+1],dp[j])+dungeon[i][j];
                if (dp[j]>0) dp[j]=0;
            }
        }
        return max(1,-1*dp[0]+1);
    }
};

/***** Second Visit *****/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int rows=dungeon.size(); int cols=dungeon[0].size();
        vector<int> dp(cols+1,INT_MAX);
        dp[cols-1]=1;
        for (int i=rows-1; i>=0; --i) {
            for (int j=cols-1; j>=0; --j) {
                dp[j]=max(1,min(dp[j+1],dp[j])-dungeon[i][j]);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        /*
            Goal maximize life
            Top down DP:
                dp[i][j] indicates the health remains in position i,j
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+dungeon[i][j]
                -2 -5 -2
                -7 -15 -1
                3  33 27
                but we maybe dead in the ahead of target, thus we need to update HP
                each time hp<=0
                0/2 0/5 3/5
                0/7 0/15 4/5
                10/7 40/7 0/6
                As we can see, we need to handle minHP.
            Bottom Up:
                We'd like to find minHP to get to P, thus we can assume we start from
                P with HP 1, and choose the easiest way for minimizing HP in each
                node.
                7   5  2
                6  11  5
                1   1  6
                Note that we must have at least 1 HP, so if we have negative HP due to
                magic orbs, we should modified it to 1.
        */
        int rows=dungeon.size(), cols=dungeon[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[rows-1][cols-1]=1-dungeon[rows-1][cols-1]>=1 ? 1-dungeon[rows-1][cols-1]:1;
        for (int i=rows-2; i>=0; --i) {
            dp[i][cols-1]=dp[i+1][cols-1]-dungeon[i][cols-1];
            if (dp[i][cols-1]<1) dp[i][cols-1]=1;
        }
        for (int j=cols-2; j>=0; --j) {
            dp[rows-1][j]=dp[rows-1][j+1]-dungeon[rows-1][j];
            if (dp[rows-1][j]<1) dp[rows-1][j]=1;
        }
        for (int i=rows-2; i>=0; --i) {
            for (int j=cols-2; j>=0; --j) {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                if (dp[i][j]<1) dp[i][j]=1;
            }
        }
        return dp[0][0];
    }
};
/***** First Visit *****/
/*
If we start from left top, in addition to minimize initial HP required to get (i,j), we also have to maximize HP left when we get (i,j) in order to decide whether we need more initial HP in the next step. It doesn't directly depend on things at (i-1,j) and (i,j-1).
*/
class Solution {
public:
    // T:O(n^2), S:O(n)
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<int> dp(n+1,INT_MAX);
        dp[n-1]=1;
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                dp[j]=max(1,min(dp[j],dp[j+1])-dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
