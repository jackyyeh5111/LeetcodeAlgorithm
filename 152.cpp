class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        /*
            enumerate all possible contiguous subarray
            (n-1)+(n-2)+...+1 => T:O(n^2)
            ---------------------
            -10 2 3 -2 4
                all the way
                standalone
                continuous to last one
            ---------------------
            dp thought is correct but here we rely on multiple information from previous
            max_dp[i-1] i.e. largest multiplication so far
            min_dp[i-1] i.e. smallest multiplication so far
            dp[i]=max(nums[i],dp[i-1]*nums[i])
                i.e. contiguous maximum or start from i
        */
        int size=nums.size();
        if (size==0) return 0;
        int imax=nums[0], imin=nums[0];
        int ans=nums[0];
        for (int i=1; i<size; ++i) {
            if (nums[i]<0) swap(imax,imin);
            imax=max(nums[i],imax*nums[i]);
            imin=min(nums[i],imin*nums[i]);
            ans=max(ans,imax);
        }
        return ans;
    }
};
