#include "utils.hpp"

/*
Input: str1 = "abac", str2 = "cab"
Output: "cabac"

// ZZZZ 必定會填入 a/b
ZZZZZZZZZZZ a/b

XXXXX a
YYY b

if a == b:
    dp[i][j] = dp[i-1][j-1] + 1
else
    dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1)

cab
abac
走上: 拿 str1
走左: 拿 str2

0    1 2 3
     c a b
1  a 2 2 2
2  b 3 3 3
3  a 4 4 4
4  c 4 5 5

backtrack 不用想得太複雜，就在 matrix 上倒過來跑即可

 */
class Solution {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n1 = str1.size();
    int n2 = str2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++) dp[i][0] = i;
    for (int j = 1; j <= n2; j++) dp[0][j] = j;

    str1 = "#" + str1;
    str2 = "#" + str2;

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (str1[i] == str2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          if (dp[i][j - 1] < dp[i - 1][j]) {
            dp[i][j] = dp[i][j - 1] + 1;
          } else {
            dp[i][j] = dp[i - 1][j] + 1;
          }
        }
      }
    }

    // backtrack
    string ans = "";
    int i = n1, j = n2;
    while (i != 0 && j != 0) {
      if (dp[i][j] == dp[i - 1][j] + 1) {
        ans = string(1, str1[i]) + ans;
        i--;
      } else if (dp[i][j] == dp[i][j - 1] + 1) {
        ans = string(1, str2[j]) + ans;
        j--;
      } else {
        ans = string(1, str1[i]) + ans;
        i--, j--;
      }
    }

    if (i) ans = str1.substr(1, i) + ans;
    if (j) ans = str2.substr(1, j) + ans;

    return ans;
  }
};

int main() {
  string str1 = "abac";
  string str2 = "cab";
  Solution sol;
  string ans = sol.shortestCommonSupersequence(str1, str2);
  std::cout << "ans: " << ans << '\n';

  str1 = "abac";
  str2 = "acba";
  ans = sol.shortestCommonSupersequence(str1, str2);
  std::cout << "ans: " << ans << '\n';
  return 0;
}