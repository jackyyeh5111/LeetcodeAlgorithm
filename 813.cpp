#include "utils.hpp"

/*
    dp[i][k]: the maximum average sum for k subarray of string s[0..i].

    XXXX [j XX i]

    dp[i][k] = max( dp[i][k], dp[j-1][k-1] + helper(s, j, i) ) for j=1,2,..,i
 */
class Solution2 {
 private:
  double averageSum(const vector<int>& nums, int start, int end) {
    return accumulate(nums.begin() + start, nums.begin() + end + 1, 0) /
           double((end - start + 1));
  }

 public:
  double largestSumOfAverages(vector<int>& nums, int K) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0));

    nums.insert(nums.begin(), 0);  // dummy value

    // init status
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = INT_MIN;  // 很容易忘記！

    double max_val = -1;
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= min(i, K); k++) {
        for (int j = k; j <= i; j++) {
          dp[i][k] = max(dp[i][k], dp[j - 1][k - 1] + averageSum(nums, j, i));

          if (i == n) { // 這裡很容易忘記！
            max_val = max(max_val, dp[i][k]);
            // cout << "i: " << i << " | j: " << j << " | k: " << k << '\n';
            // cout << "dp[i][k]: " << dp[i][k] << '\n';
          }
        }
      }
    }

    return max_val;
  }
};

/*
    這裡有錯，初始數值有漏
 */
class Solution {
 private:
  double averageSum(const vector<int>& nums, int start, int end) {
    return accumulate(nums.begin() + start, nums.begin() + end + 1, 0) /
           double((end - start + 1));
  }

 public:
  double largestSumOfAverages(vector<int>& nums, int K) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0));

    nums.insert(nums.begin(), 0);  // dummy value

    // init status
    dp[0][0] = 0;

    double max_val = -1;
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= min(i, K); k++) {
        for (int j = k; j <= i; j++) {
          dp[i][k] = max(dp[i][k], dp[j - 1][k - 1] + averageSum(nums, j, i));
          max_val = max(max_val, dp[i][k]);
        }
      }
    }

    return max_val;
  }
};

/*
X X

i = 2 | j = 1 | k = 1 ==> dp[2][1] = 1.5
i = 2 | j = 2 | k = 1 ==> dp[2][1] = 1.5

   1
 1 1
 2
 */

int main() {
  vector<int> nums{4, 1, 7, 5, 6, 2, 3};
  int k = 4;
  Solution2 sol;
  double ans = sol.largestSumOfAverages(nums, k);
  std::cout << "ans: " << ans << '\n';
  return 0;
}