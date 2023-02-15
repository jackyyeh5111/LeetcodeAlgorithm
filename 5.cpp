#include "utils.hpp"

class Solution2 {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
      dp[i][i] = true;
      dp[i][i - 1] = true; // 加了這行，下面就不需要比對 if len == 2 (厲害！)
    }
    s = '#' + s;

    // 這裏容易忘了加！ 無論如何，只要一個 char 就算是 palindromic
    string ans(1, s[1]);
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;

          if (len > ans.size()) {
            ans = s.substr(i, len);
          }
        }
      }
    }

    return ans;
  }
};

class Solution {
 public:
  /*
      X X X X [ i X X j ]

      len = 2:
          X X X X [ i j ] X X

      這裡的 dp 會是 half triangle matrix
   */
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) dp[i][i] = true;

    string ans = s.substr(0, 1);
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          if (len == 2)
            dp[i][j] = true;
          else if (dp[i + 1][j - 1])  // len > 2
            dp[i][j] = true;

          // update ans
          if (dp[i][j] && len > ans.size()) {
            ans = s.substr(i, len);
          }
        }
      }
    }

    return ans;
  }
};

int main() {
  std::string s = "aacabdkacaa";
  Solution3 sol;
  string ans = sol.longestPalindrome(s);
  std::cout << "ans: " << ans << '\n';

  s = "cbbd";
  ans = sol.longestPalindrome(s);
  std::cout << "ans: " << ans << '\n';
  return 0;
}