/*
    Enumerate all possible matrix and check sum?
    -----
    accumulate sum, i.e. prefix sum?
    for each pos(row, col), check up and left
    T:O(n^4)/S:O(n^2)
    -----
    Similar to problem 85, max area of rectangle
    T:O(n^3)/S:O(n^2)
*/

// T:O(n^3)/S:O(n^2)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<i; ++k)
                    matrix[k][j]+=matrix[i][j];
            }
            for (int k=0; k<=i; ++k)
                ans+=count(matrix[k],target);
        }
        return ans;
    }

    int count(vector<int> &v, int k)
    {
        unordered_map<int,int> mp;
        mp[0]=1;
        int csum=0,ret=0;
        for (int &num:v) {
            csum+=num;
            if (mp.count(csum-k)) ret+=mp[csum-k];
            mp[csum]++;
        }
        return ret;
    }
};

// T:O(n^4)/S:O(n^2)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
                for (int x=0; x<i; ++x) {
                    for (int y=0; y<j; ++y) {
                        ans+=dp[i][j]-dp[x][j]-dp[i][y]+dp[x][y]==target;
                    }
                }
            }
        }
        return ans;
    }
};
