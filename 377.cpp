/***** Fourth Visit *****/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0);
        dp[0]=1;
        for (int i=1; i<=target; ++i) {
            for (int &num:nums) {
                if (i<num) continue;
                dp[i]+=dp[i-num];
            }
        }
        return dp[target];
    }
};

/***** Third Visit *****/
/*
    T:O(target*n)/S:O(target)
    -----
    if numbers are negative, add a new criteria for pos/neg target range
    modify our range from target to
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        double dp[1001]={0};
        dp[0]=1;
        for (int i=1; i<=target; ++i) {
            for (const int &num:nums) {
                // modify here for pos/neg dp, e.g. i=1, check +- 1
                if (i<num) continue;
                dp[i]+=dp[i-num];
            }
        }
        return dp[target];
    }
};

/***** Second Visit *****/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<double> dp(target+1,0);
        dp[0]=1;
        for (int i=1; i<=target; ++i) {
            for (int num:nums) {
                if (i<num) continue;
                dp[i]+=dp[i-num];
            }
        }
        return dp[target];
    }
};

/***** First Visit *****/
/*
    dp problem, similar to wordbreak problem 139.
    [1 2 3], t=4
    1 2 4 4+2+1
    T:O(mn)/S:O(m), m=target, n=nums.size()
    -----
    The problem with negative numbers is that now the combinations could be potentially of infinite length. Think about nums = [-1, 1] and target = 1. We can have all sequences of arbitrary length that follow the patterns -1, 1, -1, 1, ..., -1, 1, 1 and 1, -1, 1, -1, ..., 1, -1, 1 (there are also others, of course, just to give an example). So we should limit the length of the combination sequence, so as to give a bound to the problem.

    for negative includes, we should apply recursive instead of dp.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0); dp[0]=1;
        for (int i=1; i<=target; ++i) {
            for (int num:nums) {
                if (num>i) continue;
                dp[i]+=dp[i-num];
            }
        }
        return dp.back();
    }
};
