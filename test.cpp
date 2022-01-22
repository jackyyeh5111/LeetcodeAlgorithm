
#include "utils.hpp"

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));

    // init dp matrix
    for (int i = 0; i < n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum / 2; j++) {
        if (nums[i - 1] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
      }
    }

    return dp[n][sum / 2];
  }
};

int main(int argc, char** argv) {
  Solution sol;
  bool ans;
  vector<int> nums2{1, 5, 11, 5};
  ans = sol.canPartition(nums2);
  std::cout << "ans: " << ans << '\n';

  vector<int> nums3{1, 2, 3, 5};
  ans = sol.canPartition(nums3);
  std::cout << "ans: " << ans << '\n';

  vector<int> nums4{3, 3, 3, 4, 5};
  ans = sol.canPartition(nums4);
  std::cout << "ans: " << ans << '\n';

  return 0;
}