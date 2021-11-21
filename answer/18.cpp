/***** Second Visit *****/
/*
    treat it as extension of 3Sum
    3Sum: T:O(n^2)/S:O(n)
    4Sum: n*3Sum
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i=0; i<n; ++i) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            auto rest=threeSum(nums,i+1,target-nums[i]);
            for (auto &t:rest) {
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }
        return ans;
    }

    vector<vector<int>>threeSum(vector<int>& nums, int x, int target)
    {
        int n=nums.size();
        vector<vector<int>> ans;
        for (int i=x;i<n; ++i) {
            if (i>x&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                if (sum>target) --r;
                else if (sum<target) ++l;
                else {
                    ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++; r--;
                    while(l<r&&nums[l]==nums[l-1]) ++l;
                    while(l<r&&nums[r]==nums[r+1]) --r;
                }
            }
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        /* Use 3SUM
        for (i=start to end)
          do 3sum(i+1, end)
        */
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;

                vector<int> subvector(nums.begin()+i+1, nums.end());
                vector<vector<int>> triplets = threeSum(subvector, target-nums[i]);
                for (auto triplet : triplets) {
                    triplet.push_back(nums[i]);
                    ans.push_back(triplet);
                }

        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target)
    {
        vector<vector<int>> triplets;
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1; int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum > target) r--;
                else if (sum < target) l++;
                else {
                    triplets.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++; r--;
                    while(nums[l]==nums[l-1]&&l<r) l++;
                    while(nums[r]==nums[r+1]&&l<r) r--;
                }
            }
        }
        return triplets;
    }

};

/********************* Expand to N Sum *********************/
/*
    Generally KSum solution while interview.
    Base: twoSum
    kSum: recursive on k, i.e. k-1 sum, k-2 sum, ... etc.
*/
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target)
//     {
//         sort(nums.begin(),nums.end());
//         return kSum(nums, target, 0, 4);
//     }
//
//     vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k)
//     {
//         vector<vector<int>> res;
//         if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
//             return res;
//         if (k == 2)
//             return twoSum(nums, target, start);
//         for (int i = start; i < nums.size(); ++i)
//             if (i == start || nums[i - 1] != nums[i])
//                 for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
//                     res.push_back({nums[i]});
//                     res.back().insert(end(res.back()), begin(set), end(set));
//                 }
//         return res;
//     }
//
//     vector<vector<int>> twoSum(vector<int>& nums, int target, int start)
//     {
//         vector<vector<int>> res;
//         int lo = start, hi = nums.size() - 1;
//         while (lo < hi) {
//             int sum = nums[lo] + nums[hi];
//             if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
//                 ++lo;
//             else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
//                 --hi;
//             else
//                 res.push_back({ nums[lo++], nums[hi--]});
//         }
//         return res;
//     }
// };
