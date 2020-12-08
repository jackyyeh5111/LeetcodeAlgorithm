/*
    DP solutions
    T:O(n^2)/S:O(n)
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n=nums.size(),ans=0,max_len=0;
        vector<pair<int,int>> dp(n,{1,1});
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i]<=nums[j]) continue;
                if (dp[i].first==(dp[j].first+1)) dp[i].second+=dp[j].second;
                if (dp[i].first<(dp[j].first+1)) dp[i]={dp[j].first+1,dp[j].second};
            }
            if (max_len==dp[i].first) ans+=dp[i].second;
            else if (max_len<dp[i].first) {
                max_len=dp[i].first;
                ans=dp[i].second;
            }
        }
        return ans;
    }
};
