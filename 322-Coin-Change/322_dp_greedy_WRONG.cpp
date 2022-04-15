#include "../utils.hpp"

/*
   [錯的！！！]
    wrong example:
      coins:  [1, 2, 5]
      amount: 11


    greedy
    可以先排序，從最大的數字開始找起， 第一次 dp[amount] 被更新時即可回傳
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_val = amount + 1;
    vector<int> dp(amount + 1, max_val);

    std::sort(coins.begin(), coins.end(), std::greater<>());
    print(coins);
    coins.insert(coins.begin(), -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        if (dp[amount] != max_val) return dp[amount];
      }
    }

    return -1;
  }
};

/*
  distac:
  dp[i][j]: using coins[1:i] to make up amount j.

            1 2 .. amount
  nums[0]   1 2 ..
  nums[1]   1 1 ..
*/

int main() {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  Solution sol;
  int ans = sol.coinChange(coins, amount);
  std::cout << "ans: " << ans << '\n';
  return 0;
}