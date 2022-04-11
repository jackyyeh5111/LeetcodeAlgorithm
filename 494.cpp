#include "utils.hpp"

/*
ref:
  https://hackmd.io/7LpHA0QDRD6vm7xZtY-Vvw

  Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be
target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

*/

/* dfs */
class Solution5 {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int max_sum = accumulate(nums.begin(), nums.end(), 0);
    return dfs(0, max_sum, nums, target, {});
  }

  int dfs(int idx, int max_sum, const vector<int>& nums, int target,
          vector<int> prev) {
    // print(prev);
    if (max_sum < target) return false;
    if (idx == nums.size() && target == 0) return true;

    vector<int> minus = prev;
    vector<int> plus = prev;
    minus.push_back(-nums[idx]);
    plus.push_back(nums[idx]);

    return dfs(idx + 1, max_sum - nums[idx], nums, target - nums[idx], plus) +
           dfs(idx + 1, max_sum - nums[idx], nums, target + nums[idx], minus);
  }
};

/* dfs (wrong) */
class Solution4 {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int max_sum = accumulate(nums.begin(), nums.end(), 0);
    return dfs(0, max_sum, nums, target, {});
  }

  int dfs(int idx, int max_sum, const vector<int>& nums, int target,
          vector<int> prev) {
    print(prev);
    if (max_sum < target) return false;
    if (idx == nums.size() - 1) {
      // cout << "target: " << target << '\n';
      // cout << "nums[idx]: " << nums[idx] << '\n';
      if (target == nums[idx]) {
        prev.push_back(nums[idx]);
        return true;
      }
      if (target == -nums[idx]) {
        prev.push_back(-nums[idx]);
        return true;
      }

      return false;
    }

    vector<int> minus = prev;
    vector<int> plus = prev;
    minus.push_back(-nums[idx]);
    plus.push_back(nums[idx]);

    return dfs(idx + 1, max_sum - nums[idx], nums, target - nums[idx], plus) +
           dfs(idx + 1, max_sum - nums[idx], nums, target + nums[idx], minus);
  }
};

/*
distac
dp[i][j]: the number of different expressions that you can build using nums[1:i]
to sum up j (j+bias)

   -3 -2 -1 0 1 2 3
#           1
1         1   1
1      1    1   1
1

 */
class Solution3 {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < abs(target)) return 0;  // important

    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

    int offset = sum;
    nums.insert(nums.begin(), -1);
    dp[0][offset] = 1;

    // transfer function
    /* 不能在迴圈裡面加上 offset 拉！ */
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2 * sum; j++) {
        // 2*sum >=  j - nums[i]] >= 0
        if (j >= nums[i] && dp[i - 1][j - nums[i]]) {
          dp[i][j] += dp[i - 1][j - nums[i]];
          // std::cout << "i: " << i << " | j: " << j << '\n';
        }
        // 2*sum >=  j + nums[i]] >= 0
        if (j <= 2 * sum - nums[i] && dp[i - 1][j + nums[i]]) {
          dp[i][j] += dp[i - 1][j + nums[i]];
        }
        std::cout << "i: " << i << " | j: " << j << '\n';
        print(dp);
      }
    }

    return dp[n][target + offset];
  }
};

class Solution2 {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

    int offset = sum;
    nums.insert(nums.begin(), -1);
    dp[0][offset] = 1;

    // transfer function
    /* 不能在迴圈裡面加上 offset 拉！ */
    for (int i = 1; i <= n; i++) {
      for (int j = -sum; j <= sum; j++) {
        j += offset;
        if (j >= nums[i] && dp[i - 1][j - nums[i]]) {
          dp[i][j] += dp[i - 1][j - nums[i]];
          // std::cout << "i: " << i << " | j: " << j << '\n';
        }
        if (j >= -nums[i] && dp[i - 1][j + nums[i]]) {
          dp[i][j] += dp[i - 1][j + nums[i]];
        }
        std::cout << "i: " << i << " | j: " << j << '\n';
        print(dp);
      }
    }

    return dp[n][target + offset];
  }
};

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

    if (sum < abs(target)) return 0;  // important

    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

    // init
    int offset = sum;
    dp[0][offset] = 1;

    for (int i = 0; i < n; i++) {
      // j start from nums[i] in case of out of boundary.
      for (int j = nums[i]; j <= 2 * sum - nums[i]; j++) {
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
  vector<int> nums{1, 0};
  int target = 1;

  Solution5 sol;
  int ans;
  ans = sol.findTargetSumWays(nums, target);
  std::cout << "ans: " << ans << '\n';

  // vector<int> nums2{1};
  // target = 2;
  // ans = sol.findTargetSumWays(nums2, target);
  // std::cout << "ans: " << ans << '\n';

  return 0;
}