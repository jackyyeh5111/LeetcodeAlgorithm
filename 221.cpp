/***** Second Visit *****/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size(),ans=0;
        vector<int> dp(n+1,0);
        for (int i=1; i<=m; ++i) {
            int lu=dp[0];
            for (int j=1; j<=n; ++j) {
                int tmp=dp[j];
                if (matrix[i-1][j-1]=='1')
                    dp[j]=min(dp[j],min(lu,dp[j-1]))+1;
                else dp[j]=0;
                ans=max(ans,dp[j]);
                lu=tmp;
            }
        }
        return ans*ans;
    }
};

/***** First Visit *****/
/**************** 2-D DP ****************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        /*
            111
            111
            111

            111
            122
            1

            [["1","1","1","1","0"],
             ["1","1","1","1","0"],
             ["1","1","1","1","1"],
             ["1","1","1","1","1"],
             ["0","0","1","1","1"]]

            [["1","1","1","1","0"],
             ["1","2","2","2","0"],
             ["1","2","3","3","1"],
             ["1","2","3","4","1"],
             ["0","0","1","1","1"]]

            ** Can actually reduce to 1-d dp with a prev ptr. **
        */
        int ans=0;
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        for (int i=0; i<matrix.size(); ++i) ans=max(ans,matrix[i][0]-'0');
        for (int j=0; j<matrix[0].size(); ++j) ans=max(ans,matrix[0][j]-'0');
        for (int i=1; i<matrix.size(); ++i) {
            for (int j=1; j<matrix[0].size(); ++j) {
                if (matrix[i][j]!='1') continue;
                if (matrix[i-1][j]!='0' &&
                    matrix[i][j-1]!='0' &&
                    matrix[i-1][j-1]!='0')
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
                ans=max(matrix[i][j]-'0',ans);
            }
        }
        return ans*ans;
    }
};

/**************** 1-D DP ****************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0, pre;
        vector<int> cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = cur[j];
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre, min(cur[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
                pre = temp;
            }
        }
        return sz * sz;
    }
};
