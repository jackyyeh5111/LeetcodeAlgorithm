
class Solution {
public:
    // T:O(N^2), S:O(1)
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest=INT_MAX; int ans;
        for (int i=0; i<nums.size(); ++i) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1; int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                ans = closest > abs(target-sum) ? sum : ans;
                closest = min(closest, abs(target-sum));
                if (sum>target) r--;
                else if (sum<target) l++;
                else return target;
            }
        }
        return ans;

    }
};
