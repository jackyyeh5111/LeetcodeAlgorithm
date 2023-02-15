#include "utils.hpp"

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    text1 = "#" + text1;
    text2 = "#" + text2;

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (text1[i] == text2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[n1][n2];
  }
};

/*
    XXXX i
    YYY j

    if t1[i] == t2[j]:
       dp[i][j] = max(dp[i-1][j] + 1, dp[i][j-1] + 1)
    else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    for i 0..n-1
        for j 0..n-1
 */

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    text1 = "#" + text1;
    text2 = "#" + text2;

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (text1[i] == text2[j]) {
          // 這裡是錯的！！
          /*
            問題 case：
                text1: "abcc"
                text2: "abyc"
           */
          dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
        } else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[n1][n2];
  }
};



int main() {
  string text1 = "abcde";
  string text2 = "ace";
  Solution sol;
  int ans = sol.longestCommonSubsequence(text1, text2);
  std::cout << "ans: " << ans << '\n';
  return 0;
}