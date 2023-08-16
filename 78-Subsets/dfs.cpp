class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;

         // dfs
         vector<int> subset;
         dfs(nums, ans, subset, 0);
         return ans;
    }
    void dfs(const vector<int>& nums, vector<vector<int>> &ans, vector<int> &subset, int idx) {
      if (idx == nums.size()) {
        ans.push_back(subset);
        return;
      }
      subset.push_back(nums[idx]);
      dfs(nums, ans, subset, idx + 1);
      subset.pop_back();
      dfs(nums, ans, subset, idx + 1);
    }
};

/* 
  subset: [1 2]

  ans: [
    [1 2 3]
    [1 2 ]
    [1]
    [2 3]
    [2]
    [3]
  ]
 */