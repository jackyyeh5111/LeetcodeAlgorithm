#include "utils.hpp"

/*
    區間性 dp

    - dp size == n+1，因為這樣比較好想！

    ex:
        XXiXXXXj
        dp[i][j] = dp[i+1][j-1] + 2
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
          // 雖然有可能 i + 1 < j - 1，但因為 default value = 0，所以不影響
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }

    return dp[1][n];
  }
};

int main() {
  std::string s = "cbbd";
  Solution sol;
  int ans = sol.longestPalindromeSubseq(s);
  std::cout << "ans: " << ans << '\n';
  return 0;
}