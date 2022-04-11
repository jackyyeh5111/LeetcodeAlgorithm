#include "utils.hpp"

/*
  ref:
    https://hackmd.io/2e_TqyyQSoiDooy8qCwaXQ
    
  XXX [ i XX j ]
*/
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    s = "#" + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }

    return dp[1][n];
  }
};

int main() {
  std::string s = "cbbdb";
  Solution sol;
  int ans = sol.longestPalindromeSubseq(s);
  std::cout << "ans: " << ans << '\n';
  return 0;
}