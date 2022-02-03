#include "utils.hpp"

/*
    dp[i][j]: the maximum coins you can collect in nums[i:j]

    XXXX B XXXX
    i    k    j

    # transfer function
    dp[i][j] = dp[i][k-1] + dp[k+1][j] + helper(nums, i, j)

    // 這裡要特別注意，因為 k 氣球是 balloon[i:j] 最後一個破掉的，所以 
    // return nums[k-1]*nums[k]*nums[k+1] 是錯誤的！！
    // 
    // 補充：
    //      不能定義 dp 是將 k 優先戳破，將 k 戳破後，會影響到 dp[i:k-1] 的分數，
    //      如此 dp 就跟未來有關，無法算
    int helper(nums, i, j) {
        return nums[i-1]*nums[k]*nums[j+1]
    }
 */
class Solution2 {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        for (int k = i; k <= j; k++) {
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                       nums[i - 1] * nums[k] * nums[j + 1]);
        }
      }
    }

    return dp[1][n];
  }
};

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        for (int k = i; k <= j; k++) {
          // 這裡是錯的！！！
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                       nums[k - 1] * nums[k] * nums[k + 1]);
        }
      }
    }

    return dp[1][n];
  }
};

int main() {
  vector<int> nums{3, 1, 5, 8};
  Solution2 sol;
  int ans = sol.maxCoins(nums);
  cout << "ans: " << ans << '\n';
  return 0;
}