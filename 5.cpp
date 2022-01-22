#include "utils.hpp"

class Solution2 {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) return s;

    s = "#" + s;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) dp[i][i] = true;

    // 這裏容易忘了加！ 無論如何，只要一個 char 就算是 palindromic
    string ans = string(1, s[1]);
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && (i == j - 1 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          if (len > ans.size()) ans = s.substr(i, len);
        }
      }
    }

    return ans;
  }
};

/*
    區間性 dp

    - dp size == n+1，因為這樣比較好想！

    ex:
        XXiXXXXj
        if i == j:
            dp[i][j] = dp[i+1][j-1] + 2
        else:
            dp[i][j] = dp[i+1][j-1] + 2
 */

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) return s;

    s = "#" + s;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) dp[i][i] = true;

    string ans = "";
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n - len + 1; i++) {
        int j = i + len - 1;
        // 這裡判斷式子有錯，有可能 i + 1 < j - 1，且 default value = false
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (len > ans.size()) ans = s.substr(i, len);
        }
      }
    }

    return ans;
  }
};

int main() {
  std::string s = "babad";
  Solution2 sol;
  string ans = sol.longestPalindrome(s);
  std::cout << "ans: " << ans << '\n';

  s = "cbbd";
  ans = sol.longestPalindrome(s);
  std::cout << "ans: " << ans << '\n';
  return 0;
}