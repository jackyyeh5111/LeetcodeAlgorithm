#include "utils.hpp"

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }

    return dp[amount];
  }
};

int main() {
  std::vector<int> coins = {1, 2, 5};
  int amount = 4;
  Solution sol;
  int ans = sol.change(amount, coins);
  std::cout << "ans: " << ans << '\n';
  return 0;
}