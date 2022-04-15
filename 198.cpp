#include "utils.hpp"

/* ref:
    https://www.youtube.com/watch?v=IcEX9Oi_tao
 */

/* Approach 3: dp (dual status)
    dp[i] = max(dp[i-1], dp[i-2] + nums[i])

    Sapce: O(1)
*/
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    int temp = max(nums[0], nums[1]);
    int temp2 = nums[0];

    for (int i = 2; i < n; i++) {
      int new_temp = max(temp, temp2 + nums[i]);
      temp2 = temp;
      temp = new_temp;
    }

    return temp;
  }
};

/* Approach 2: dp (bottom-up)
    dp[i] = max(dp[i-1], dp[i-2] + nums[i])

    Sapce: O(n)
*/
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
  }
};

/* Approach 1: recursion (top-down)*/
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    dp = vector<int>(n, 0);
    return rob(nums, n - 1);
  }

 private:
  int rob(const vector<int>& nums, int i) {
    if (i < 0) return 0;
    if (dp[i] != 0) return dp[i];
    dp[i] = max(rob(nums, i - 1), rob(nums, i - 2) + nums[i]);
    return dp[i];
  }

  vector<int> dp;
};

int main() {
  vector<int> nums{2, 7, 9, 3, 1};
  Solution sol;
  int ans = sol.rob(nums);
  std::cout << "ans: " << ans << '\n';
  return 0;
}