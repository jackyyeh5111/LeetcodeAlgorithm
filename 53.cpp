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
