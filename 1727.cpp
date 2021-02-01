/*
	Similar concept as  problem 84. / problem 85.
	Maintain contiguous bar(column) by processing each row.
    T:O(mnlogn)/S:O(n)
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<int> dp(n,0);
        for (int i=0; i<m; ++i) {
            vector<int> tmp;
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]) dp[j]++;
                else dp[j]=0;
                tmp.push_back(dp[j]);
            }
            sort(tmp.begin(),tmp.end());
            for (int j=0; j<n; ++j) 
                ans=max(ans,tmp[j]*(n-j));
        }
        return ans;
    }
};