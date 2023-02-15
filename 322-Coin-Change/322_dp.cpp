#include "../utils.hpp"

/* ref:
    https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution

    dp[i][j]: min coins to make up amount j using first i coins.

    狀態壓縮

    dp:
                  0 1 ..       ...       amount
    {nums[0]}   | 0 1 2 3 4 5 6 7 8 9 10 11
    {nums[0:2]} | 0 1 1 2 2 3 3 4 4 5 5 6
    {nums[0:3]} | 0 1 1 2 2 1 2 2 3 3 2 3
 */

/* Approach 1
    之前儲存的欄位若沒有需要用到，space 都可以再壓縮
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_val = amount + 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, max_val));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= coins.size(); i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] > j)
          dp[i][j] = dp[i - 1][j];  // 這行一直忘了加，導致答案出錯！
        else
          dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - coins[i - 1]] + 1,
                          dp[i][j - coins[i - 1]] + 1});
      }
    }

    return dp[n][amount] == max_val ? -1 : dp[n][amount];
  }
};

int main() {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  SolutionTest sol;
  int ans = sol.coinChange(coins, amount);
  std::cout << "ans: " << ans << '\n';
  return 0;
}