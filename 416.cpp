/***** Third Visit *****/
// DP T:O(n*k)/S:O(k), n denotes # of nums and k denotes max possible num.
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size(), tgt=0;
        for (int num:nums) tgt+=num;
        if (tgt%2) return false;
        else tgt/=2;
        vector<bool> dp(20001,0);
        dp[0]=1;
        for (int i=0; i<n; ++i) {
            for (int j=20000; j>=1; --j) {
                if (j>=nums[i])
                    dp[j]=dp[j]||dp[j-nums[i]];
            }
        }
        return dp[tgt];
    }
};

// bitset T:O(n*k)/S:O(k), n denotes # of nums and k denotes max possible num.
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int tgt=accumulate(nums.begin(),nums.end(),0);
        if (tgt%2) return false;
        else tgt/=2;
        bitset<200001> bs;
        bs[0]=1;
        for (int num:nums)
            bs=bs|(bs<<num);
        return bs[tgt];
    }
};

/***** Second Visit *****/
/*
    1 2 3 4 5 6
    backtracking?
    TLE
    -----
    0/1 knapsack DP
    normal: 2-D
    efficient: 1-D, to do so, we need to iterate backward instead of forward.
    T:O(nk)/S:O(k)
    profit: bool flag true
    volume: each num
    capacity: sum/2
    -----
     0 1 2 3 ... tgt [capacity]
    0
    1
    2
    .
    .
    n
    [# of items]
    -----
    bit manipulation to reduce each num's checking (row).
    T:O(n)/S:O(1)
*/

// bit manipulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1); // maxnums * max_value / 2
        int sum=0;
        for (int num:nums) {
            sum+=num;
            bits|=bits<<num;
        }
        return (sum%2==0)&&bits[sum/2];
    }
};


// 2-D 0/1 knapsack
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int num:nums) sum+=num;
        if (sum%2) return false;
        int n=nums.size();
        int tgt=sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(tgt+1,0));
        dp[0][0]=1;
        for (int i=1; i<=n; ++i) {
            dp[i][0]=1;
            for (int j=1; j<=tgt; ++j) {
                dp[i][j]=dp[i-1][j];
                if (j>=nums[i-1])
                    dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][tgt];
    }
};

// 1-D 0/1 knapsack
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int num:nums) sum+=num;
        if (sum%2) return false;
        int n=nums.size();
        int tgt=sum/2;
        vector<bool> dp(tgt+1,0); dp[0]=1;
        for (int num:nums) {
            for (int j=tgt; j>=num; --j) {
                dp[j]=dp[j]|dp[j-num];
            }
        }
        return dp[tgt];
    }

};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for (int num:nums) sum+=num;
        if (sum%2) return false;
        bool ans=false;
        dfs(nums,ans,0,0,sum/2);
        return ans;
    }

    void dfs(vector<int> &nums, bool &ans, int idx, int cur, int target)
    {
        if (cur>target||idx>=nums.size()) return;
        else if (cur==target) {ans=true; return;}
        dfs(nums,ans,idx+1,cur,target);
        dfs(nums,ans,idx+1,cur+nums[idx],target);
    }
};

/***** First Visit *****/
/*
    w= 14,9,8,4,3,2
    capacity= 40/2
    dp[i][j] means with items 0~i, if we can sum up to j or not.
    >> Reduce to 1-d DP.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int total=0,target=0;;
        for(int num:nums) total+=num;
        if (total%2!=0) return false;
        else target=total/2;
        vector<bool> dp(total+1, false);
        dp[0]=true;
        for (int num:nums) {
            for (int k=target; k>=num; --k) {
                dp[k]=dp[k]||dp[k-num];
            }
        }
        return dp[target];
    }
};
