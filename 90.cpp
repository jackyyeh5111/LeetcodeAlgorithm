#include "utils.hpp"

/* Visit 1
ref:
https://medium.com/@ChYuan/leetcode-90-subsets-ii-%E5%BF%83%E5%BE%97-medium-f6eaa6f6ee23
 */
class Solution {
 public:
  vector<vector<int>> ans;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    generateSubs(nums, {}, 0);
    return ans;
  }

  void generateSubs(const vector<int> &nums, vector<int> subset, int begin) {
    ans.push_back(subset);
    for (int i = begin; i < nums.size(); i++) {
      if (i > begin && nums[i] == nums[i - 1]) continue;
      subset.push_back(nums[i]);
      generateSubs(nums, subset, i + 1);
      subset.pop_back();
    }
  }
};

int main(int argc, char **argv) {
  vector<int> nums{1, 2, 2};
  Solution sol;
  vector<vector<int>> ans = sol.subsetsWithDup(nums);
  print(ans);

  return 0;
}