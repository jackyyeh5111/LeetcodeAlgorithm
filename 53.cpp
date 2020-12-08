/***** Second Visit *****/
/*
    brute force:
    enumerate all possible contiguous arrays.
    T:O(n^2 pairs * n checking)/S:O(1)
    -----
    Array
    1. 2 ptr
    2. binary search
    3. moving window
    4.  2-d
        DP
        greedy
        divide & conquer
    -----
    Here we use moving window as a greedy approach, for each step we update current max/min.
    T:O(n)/S:O(1)
    -----
    DP solutioin, dp[i] denotes max contiguous sum ends in position i
    dp[i]=dp[i-1]<=0?nums[i]:dp[i-1]+nums[i];
    then find max while ietrating.
    T:O(n)/S:O(n) -> could be reduce to constance space complexity, as above.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size()==0) return 0;
        else if(nums.size()==1) return nums[0];
        int ans=nums[0], cmin=nums[0], acc=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            acc+=nums[i];
            cmin=min(cmin,acc-nums[i]);
            ans=max(ans,cmin<0?acc-cmin:acc);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // T:O(n)
        if (nums.size()==0) return 0;
        int acc=nums[0]; int smallest=nums[0];
        int ans=nums[0];
        for (int i=1; i<nums.size(); ++i){
            acc+=nums[i];
            ans=max(max(ans,acc-smallest),acc);
            if(acc<smallest) smallest=acc;
        }
        return ans;
    }
};

/**************** Divide and Conqure ****************/

class Solution {
public:
    // T(n)=2T(n/2)+O(n)
    // T:O(nlogn)
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
