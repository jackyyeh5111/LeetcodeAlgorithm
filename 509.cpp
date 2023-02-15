#include "utils.hpp"

// use variable register instead of dp array
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int n0 = 0;
    int n1 = 1;
    for (int i = 2; i <= n; ++i) {
      int temp = n1;
      n1 = n1 + n0;
      n0 = temp;
    }

    return n1;
  }
};

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