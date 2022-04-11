#include "utils.hpp"

/*

    1 2 ... n

    if i pick k as the root

          k
        /   \
    1~k-1   k+1~n

    transfer:
    dp[k] = dp[k-1] * dp[n-(k+1)+1]

 */
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }

    return dp[n];
  }
};

int main() {
  Solution sol;
  int n = 3;
  int ans = sol.numTrees(n);
  std::cout << "ans: " << ans << '\n';
  return 0;
}