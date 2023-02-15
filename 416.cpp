#include "utils.hpp"

/*
    ref:
    https://hackmd.io/FYtK5m3IShaIFGOKLZSANg
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624390/C%2B%2B-Brute-Force-To-Optimized-SolutionO(N)-Time-or-W-Explanation
 */

/* Approach 4: bitset  */
class Solution4 {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    std::bitset<10001> bits(1);
    for (const int& num : nums) {
      bits |= bits << num;
      if (bits[sum / 2]) return true;
    }

    return false;
  }
};

/* Approach 3: DP - Space Optimized  */
/*
    - Instead of creating a 2-D array dp[n+1][sum/2+1], we can solve this
   problem using an array dp[sum/2+1] only. That is, since we only use the
   current index and previous index, the rest of the indexes are a waste of
   space and we can reduce it to O(sum/2) space.
 */
class Solution3 {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    sum /= 2;
    nums.insert(nums.begin(), 0);

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    /* 切記，iterate j 必須 reverse iterate，如果 forward iterate 會重複使用同個
     * element */
    for (int i = 1; i <= n; i++) {
      for (int j = sum; j >= nums[i]; j--) {
        if (dp[j - nums[i]]) dp[j] = true;
      }
    }

    /* wrong (forward iterate) */
    // for (int i = 0; i < nums.size(); ++i) {
    //   for (int j = nums[i]; j <= sum; ++j) {

    return dp[sum];
  }
};

/* Approach 2: DP */
// 矩陣可以節省 space，只要 (n+1) * sum / 2 即可，不需要 (n+1) * sum
class Solution2 {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    sum /= 2;
    nums.insert(nums.begin(), 0);  // dummy
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // init dp matrix
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= sum; j++) {
        if (nums[i] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
      }
    }

    return dp[n][sum];
  }
};

/* Approach 1: Brute Force - Recursion */
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum % 2 == 0 && dfs(nums, sum / 2, 0);
  }

  bool dfs(const vector<int>& nums, int sum, int idx) {
    if (sum == 0) return true;
    if (idx >= nums.size() || sum < 0) return false;
    return dfs(nums, sum - nums[idx], idx + 1) || dfs(nums, sum, idx + 1);
  }
};

int main(int argc, char** argv) {
  SolutionTest sol;
  bool ans;
  vector<int> nums{1, 2, 5};
  ans = sol.canPartition(nums);
  std::cout << "ans: " << ans << '\n';

  // vector<int> nums2{1, 5, 11, 5};
  // ans = sol.canPartition(nums2);
  // std::cout << "ans: " << ans << '\n';

  // vector<int> nums3{1, 2, 3, 5};
  // ans = sol.canPartition(nums3);
  // std::cout << "ans: " << ans << '\n';

  return 0;
}