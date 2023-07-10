#include "../utils.hpp"

/* ref:
    https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution

    狀態壓縮

    dp:
                  0 1 ..       ...       amount
    {nums[0]}   | 0 1 2 3 4 5 6 7 8 9 10 11
    {nums[0:1]} | 0 1 1 2 2 3 3 4 4 5 5 6
    {nums[0:2]} | 0 1 1 2 2 1 2 2 3 3 2 3
 */

class Solution2 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_val = amount + 1;
    vector<int> dp(amount + 1, max_val);

    dp[0] = 0;

    /* 兩個迴圈已經有考慮到同個 coin 重複使用！ */
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }

    return dp[amount] == max_val ? -1 : dp[amount];
  }
};

int main() {
  std::vector<int> coins = {1};
  int amount = 0;
  Solution2 sol;
  int ans = sol.coinChange(coins, amount);
  std::cout << "ans: " << ans << '\n';
  return 0;
}