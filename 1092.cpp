#include "utils.hpp"

/*
    xxxx i
    ooo j

    definition:
        dp[i][j]: min num of superseq
    init:
        dp[i][0] = i   for i = 1 .. n1
        dp[0][j] = j   for j = 1 .. n2
    transfer:
        if (s1[i] == s2[j])
            dp[i][j] = dp[i-1][j-1] + 1
        else
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1

    ex:
         # c a b
       # 0 1 2 3
       a 1 2 2 3
       b 2 3 3 3
       a 3 4 ..
       c 4 5 ..

      backtrack 不用想得太複雜，就在 matrix 上倒過來跑即可

*/
enum class bt {
    from_s1,
    from_s2,
    from_both
};
class Solution3 {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        str1 = "#" + str1;
        str2 = "#" + str2;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; ++i) dp[i][0] = i;
        for (int j = 1; j <= n2; ++j) dp[0][j] = j;
        vector<vector<bt>> prev(n1 + 1, vector<bt>(n2 + 1));
        for (int i = 1; i <= n1; ++i) prev[i][0] = bt::from_s1;
        for (int j = 1; j <= n2; ++j) prev[0][j] = bt::from_s2;

        // transfer function
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i] == str2[j]) {
                    prev[i][j] = bt::from_both;
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if (dp[i][j-1] < dp[i-1][j]) {
                    prev[i][j] = bt::from_s2;
                    dp[i][j] = dp[i][j-1] + 1;
                }
                else {
                    prev[i][j] = bt::from_s1;
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }

        // backtrace
        string ans = "";
        int i = n1, j = n2;
        while(i != 0 || j != 0){
            if (prev[i][j] == bt::from_s1) {
                ans = str1[i] + ans;
                --i;
            }
            else if (prev[i][j] == bt::from_s2) {
                ans = str2[j] + ans;
                --j;
            }
            else if (prev[i][j] == bt::from_both) {
                ans = str1[i] + ans;
                --i; --j;
            }
            else {
              std::cout << "ERROR!\n";
            }
        }

        return ans;
    }
};


class Solution2 {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n1 = str1.size();
    int n2 = str2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    vector<vector<int>> prev(n1 + 1, vector<int>(n2 + 1));
    str1 = '#' + str1;
    str2 = '#' + str2;

    for (int i = 1; i <= n1; i++) {
      prev[i][0] = 2;
      dp[i][0] = i;
    }
    for (int j = 1; j <= n2; j++) {
      prev[0][j] = 1;
      dp[0][j] = j;
    }

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (str1[i] == str2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          prev[i][j] = 0;
        } else if (dp[i][j - 1] < dp[i - 1][j]) {
          dp[i][j] = dp[i][j - 1] + 1;
          prev[i][j] = 1;
        } else {
          dp[i][j] = dp[i - 1][j] + 1;
          prev[i][j] = 2;
        }
      }
    }

    int i = n1, j = n2;
    string ans = "";
    while (i >= 0 && j >= 0) {
      if (prev[i][j] == 0) {
        ans = str1[i] + ans;
        --i, --j;
      } else if (prev[i][j] == 1) {
        ans = str2[j] + ans;
        --j;
      } else {
        ans = str1[i] + ans;
        --i;
      }
    }

    ans.erase(0, 1);
    return ans;
  }
};

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

    return ans.substr();
  }
};

int main() {
  string str1 = "abac";
  string str2 = "cab";
  SolutionTest sol;
  string ans = sol.shortestCommonSupersequence(str1, str2);
  std::cout << "ans: " << ans << '\n';

  str1 = "abac";
  str2 = "acba";
  ans = sol.shortestCommonSupersequence(str1, str2);
  std::cout << "ans: " << ans << '\n';
  return 0;
}