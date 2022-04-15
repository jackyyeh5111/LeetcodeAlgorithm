#include "../utils.hpp"

/*
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be
target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

為了節省 dp 空間，可以用 map 來儲存即可！
How to save space:
1. 原本的 dp 是 2D array, 改用 unordered_map 後成為 1D array，只要每個 iter
更新即可
2. 原本每個 iter 都給 2 * sum 的空間，改成 map 後只需要給有值的欄位即可
*/

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      unordered_map<int, int> next_dp;
      for (auto pair : dp) {
        next_dp[pair.first + nums[i]] += pair.second;
        next_dp[pair.first - nums[i]] += pair.second;
      }

      dp = next_dp;
    }

    return dp[target];
  }
};

int main(int argc, char** argv) {
  vector<int> nums{1, 0};
  int target = 1;

  Solution sol;
  int ans;
  ans = sol.findTargetSumWays(nums, target);
  std::cout << "ans: " << ans << '\n';

  // vector<int> nums2{1};
  // target = 2;
  // ans = sol.findTargetSumWays(nums2, target);
  // std::cout << "ans: " << ans << '\n';

  return 0;
}