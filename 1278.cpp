#include "utils.hpp"

/*
    dp[i][k]: the minimum number of characters that you need to change to divide
              the string s[0..i] into k substrings that are all palindromes.
    [XXXX][j XXX i]

    tranfer function:
        dp[i][k] = min{ dp[j-1][k-1] + helper(s, j, i) } for j=1,2,..,i

    basic IV template:
        for (int i=1; i <= srt_len;i++) {
            for (int k=1; k <= min(i, K); k++) {
                for (int j=k; j <= i; j++) {
                    dp[i][k] = min{ dp[j-1][k-1] + helper(s, j, i) }
                }
            }
        }
 */
class Solution2 {
 public:
  int helper(string s, int start, int end) {
    int len = end - start + 1;
    if (len < 2) return 0;
    string sub_str = s.substr(start, len);
    int num_change = 0;
    /*
    abc
    aabb
    */
    for (int i = 0; i < len / 2; i++) {
      if (sub_str[i] != sub_str[len - 1 - i]) ++num_change;
    }

    return num_change;
  }

  int palindromePartition(string s, int K) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(K + 1, n));

    dp[0][0] = 0;
    s = '#' + s;

    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= min(i, K); k++) {
        for (int j = k; j <= i; j++) {
          dp[i][k] = min(dp[j - 1][k - 1] + helper(s, j, i), dp[i][k]);
        }
      }
    }

    return dp[n][K];
  }
};

class Solution {
 private:
  int helper(const string s, int start, int end) {
    string sub_str = s.substr(start, end - start + 1);
    int n = sub_str.size();
    if (n < 2) return 0;

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
      if (sub_str[i] != sub_str[n - 1 - i]) ans++;
    }

    return ans;
  }

 public:
  int palindromePartition(string s, int K) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(K + 1, n));
    dp[0][0] = 0;

    s = "#" + s;

    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= min(i, K); k++) {
        for (int j = k; j <= i; j++) {
          int count_change = helper(s, j, i);
          dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + count_change);
        }
      }
    }

    return dp[n][K];
  }
};

int main() {
  string s = "abc";
  int k = 2;
  Solution2 sol;
  int ans = sol.palindromePartition(s, k);
  std::cout << "ans: " << ans << '\n';
  return 0;
}