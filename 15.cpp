/***** Third Visit *****/
/*
    find UNIQUE triplets
    sort first then treat each num as root, i.e. the first element of triplet.
    use a set to save time for checking num exist or not
    T:O(nlogn+n)/S:O(n)
    FAIL!!!
    -------
    sort first then treat each num as root, i.e. the first element of triplet.
    then we can reduce to 2Sum problem.
    ** For sorted array, think binary search / 2 ptr solution !! **
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if (n<=2) return ans;
        sort(nums.begin(),nums.end());
        for (int i=0; i<n; ++i) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r) {
                if (nums[l]+nums[r]==-nums[i]) {
                    ans.push_back(vector<int>{nums[i],nums[l++],nums[r--]});
                    while(l<r&&nums[l]==nums[l-1]) l++;
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                else if (nums[l]+nums[r]>-nums[i]) r--;
                else l++;
            }
        }
        return ans;
    }
};

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
