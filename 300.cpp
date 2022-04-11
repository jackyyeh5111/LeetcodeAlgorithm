#include "utils.hpp"

class Solution2 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
          ans = max(ans, dp[i]);
        }
      }
    }

    return ans;
  }
};

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    /* 這邊還要另外檢查太麻煩，直接在 iter dp 時設個變數保存極值就可 */
    int max_len = -1;
    for (int i = 0; i < n; i++) {
      max_len = max(dp[i], max_len);
    }

    return max_len;
  }
};