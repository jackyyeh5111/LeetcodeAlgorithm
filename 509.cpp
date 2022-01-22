#include "utils.hpp"

class Solution {
 public:
  int fib(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

int main() {
  Solution sol;
  int ans = sol.fib(0);
  std::cout << "ans: " << ans << '\n';
  return 0;
}