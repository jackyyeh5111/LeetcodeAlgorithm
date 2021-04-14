/*
    dfs(nums,l,r,multipliers,k,cur,ans)
      dfs(nums,l+1,r,multipliers,k+1,cur+nums[l]*multipliers[k],ans)
      dfs(nums,l,r-1,multipliers,k+1,cur+nums[r]*multipliers[k],ans)
    T:O(2^k) -> TLE
    -----
    Use dp to reduce complexity
    MEMOISE DP!!!
*/

// recursive/iterative
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        queue<vector<int>> q; // score, l, j
        int n=nums.size(), m=multipliers.size();
        q.push({0,0,n-1});
        for (int i=0; i<m; ++i) {
            int k=q.size();
            while(k--) {
                auto p=q.front(); q.pop();
                q.push({p[0]+multipliers[i]*nums[p[1]],p[1]+1,p[2]});
                q.push({p[0]+multipliers[i]*nums[p[2]],p[1],p[2]-1});
            }
        }
        int ans=INT_MIN, k=q.size();
        while(k--) {
            auto p=q.front(); q.pop();
            ans=max(ans,p[0]);
        }
        return ans;
    }
};

// memoise dp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        vector<vector<int>> dp(1001,vector<int>(1001,INT_MIN));
        return dfs(dp,nums,multipliers,0,0);
    }

    int dfs(vector<vector<int>> &dp, vector<int>& nums, vector<int>& multipliers, int l, int i)
    {
        if (i>=multipliers.size()) return 0;
        else if (dp[l][i]!=INT_MIN) return dp[l][i];
        int r=nums.size()-(i-l+1);
        dp[l][i]=max(dfs(dp,nums,multipliers,l+1,i+1)+multipliers[i]*nums[l],
                     dfs(dp,nums,multipliers,l,i+1)+multipliers[i]*nums[r]);
        return dp[l][i];
    }
};
