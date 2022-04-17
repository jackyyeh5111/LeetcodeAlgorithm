#include "utils.hpp"

class Solution2 {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
      dp[i][i] = true;
      dp[i][i - 1] = true;
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
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) return s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    s = '#' + s;

    int ans_start = 1, ans_end = 1;
    int max_num = 1;
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          if (len == 2) {
            dp[i][j] = 2;
          } else if (dp[i + 1][j - 1]) {
            dp[i][j] = dp[i + 1][j - 1] + 2;
          }

          if (dp[i][j] > max_num) {
            max_num = dp[i][j];
            ans_start = i;
            ans_end = j;
          }
        }
      }
    }

    return s.substr(ans_start, ans_end - ans_start + 1);
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