/********************** Second Visit **********************/
// Fail
/*
    Notice if target<0, we can break the loop.
    After sorting , we can sure a<b<c
    target = -1*a = b+c
    it target<0 -> a>0 -> b+c >0
    there's no way b+c <0 thus we can break the loop.
*/

/********************** First Visit **********************/
class Solution {
public:
    // T: O(N^2)+O(NlogN) S:O(N)
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            int target = -1*nums[i];
            int l=i+1; int r=nums.size()-1;
            while(l<r) {
                if (nums[l]+nums[r]>target) r--;
                else if (nums[l]+nums[r]<target) l++;
                else {
                    vector<int> triplet{nums[i],nums[l],nums[r]};
                    ans.push_back(triplet);
                    l++; r--;
                    while (nums[l]==nums[l-1]&&l<r) l++;
                    while (nums[r]==nums[r+1]&&l<r) r--;

                }
            }
        }
        return ans;

    }
};
