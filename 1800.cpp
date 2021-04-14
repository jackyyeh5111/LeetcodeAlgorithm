class Solution {
public:
    int maxAscendingSum(vector<int>& nums)
    {
        int csum=nums[0], n=nums.size(), ans=nums[0];
        for (int i=1; i<n; ++i) {
            if (nums[i]>nums[i-1]) csum+=nums[i];
            else csum=nums[i];
            ans=max(ans,csum);
        }
        return ans;
    }
};
