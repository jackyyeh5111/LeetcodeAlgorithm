#include "utils.hpp"

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();

        // init dp
        vector<vector<bool>> dp(N, vector<bool>(N));
        for (int i = 1; i < N; i++) {
            dp[i][i] = true;
            dp[i][i-1] = true;
        }

        // solve dp
        /* 
            XX[YYY]X
             i
                   j
         */
        string ans = string(1, s[0]);
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i <= N - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j] && len > ans.size())
                        ans = s.substr(i, len);
                }
            }
        }
        return ans;
    }
};

/* 
    dp[i][j]: substring s[i:j] is a palindromic or not?

    XX[YYY]X
     i
           j

    baab
    i
       j
 
    dp
        0 1 2 3
     0  T F F F
     1  F T F F
     2  F F T F
     3. F F F T
 */

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