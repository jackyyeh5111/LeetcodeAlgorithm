#include "utils.hpp"

/* Approach 1: dp

# definition
nums.size(): m
2*sum(nums)+1: n
create a m*n dp matrix(default value = false)

# formula
dp[i][j]: # of ways sum up to j using nums[0~i]
dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]

# init status
init: dp[-1][0] = 1

# answer
dp[i-1][target]

*/
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

    // init
    int offset = sum;
    dp[0][offset] = 1;

    // dp implement
    for (int i = 0; i < n; i++) {
      for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; j++) {
        if (dp[i][j]) {
          dp[i + 1][j + nums[i]] += dp[i][j];
          dp[i + 1][j - nums[i]] += dp[i][j];
        }
      }
    }

    return dp[n][target + offset];
  }
};

int main(int argc, char** argv) {
  vector<int> nums{1, 1, 1, 1, 1};
  int target = 3;
  bool ans;
  Solution sol;
  ans = sol.findTargetSumWays(nums, target);
  std::cout << "ans: " << ans << '\n';

  //   vector<int> nums3{1, 2, 3, 5};
  //   ans = sol.canPartition(nums3);
  //   std::cout << "ans: " << ans << '\n';

  return 0;
}