/* 
  Correct

  Note:
    two_pointers is a better approach. 
 */
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums)
          ++um[num];
        
        sort(nums.begin(), nums.end());

        int N = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
          for (int j = i + 1; j < N; ++j) {
            int target = 0 - nums[i] - nums[j];

            if (target < nums[j])
              continue;
            if (um.find(target) == um.end())
              continue;
            
            int num_target = um[target];
            if (nums[i] == target) --num_target;
            if (nums[j] == target) --num_target;
            if (num_target == 0)
              continue;

            ans.push_back({nums[i], nums[j], target});

            // put while loop here
            while(j < N - 1 && nums[j+1] == nums[j])
              ++j;
          }
          // put while loop here
          while(i < N - 1 && nums[i+1] == nums[i])
              ++i;
        }
        return ans;
    }
};

/* 
  Heap overflow!

  Failed case:
    [0,0,0,0]
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums)
          ++um[num];
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
          
          // avoid repeated ans
          while(i > 0 && nums[i] == nums[i-1])
              ++i;

          for (int j = i + 1; j < nums.size(); ++j) {
            while(j > i + 1 && nums[j] == nums[j-1])
              ++j;
            int target = 0 - nums[i] - nums[j];
            if (target < nums[j]) // avoid repeated ans
              continue;
            if (um.find(target) == um.end())
              continue;
            
            int num_target = um[target];
            if (nums[i] == target) --num_target;
            if (nums[j] == target) --num_target;
            if (num_target == 0)
              continue;

            ans.push_back({nums[i], nums[j], target});
          }
        }
        return ans;
    }
};