#include "utils.hpp"

/*
    # definition:
    dp[i]: the minimum number of stickers we have to use to achieve i status.

    用 bit 當作狀態，每個 char 都代表一個 bit

    "hello" ==> dp[31]
    0000..00011111

    "lo" ==> dp[5]
    0000..00000101
    0000..00000011

    "he" ==> dp[24]
    0000..00011000

    transfer function:
    int j = findNextStatus(i, target, str)
    dp[j] = min( dp[j], dp[i]+1 )

    #####################################
    這裡有一點要特別注意！!!!
    如果用現在的狀態找前一個狀態的話會是有問題的

    transfer function:
        int j = findPrevStatus(i, target, str)
        dp[i] = min( dp[i], dp[j]+1 )

    ex:
        // 在 "abc" 這個狀態的時候，我們無法得知 'a' 是從 "ac" or "ab"貢獻過來的
        // 所以 dp 轉移方程必須從現在的狀態找未來的狀態
        "ac" + "ab" -> "abc"
    #####################################
 */

// class Solution {
//  public:
//   int minStickers(vector<string>& stickers, string target) {
//     int n = target.size();
//     vector<int> dp(1 << n, INT_MAX);
//     dp[0] = 0;

//     for (int state = 0; state < (1 << n); state++) {
//       if (dp[state] == INT_MAX) continue;
//       for (string str : stickers) {
//         int new_state = findNextStatusByUsingStr(state, target, str);
//         dp[new_state] = min(dp[new_state], dp[state] + 1);

//         cout << "i: " << bitset<6>(state) << " | j: " << bitset<6>(new_state)
//              << '\n';
//         cout << "dp[i]: " << dp[state] << " | dp[j]: " << dp[new_state] <<
//         '\n';
//       }
//     }
//     return dp[(1 << n) - 1] == INT_MAX ? -1 : dp[(1 << n) - 1];
//   }

//   int findNextStatusByUsingStr(int status, string target, string s) {
//     int n = target.size();
//     for (auto ch : s) {
//       // loop over each character in target, if equals to ch and not filled,
//       // then set as filled
//       for (int k = 0; k < n; k++) {
//         if (((status >> k) & 1) == 0 && target[k] == ch) {
//           status = status + (1 << k);
//           break;
//         }
//       }
//     }
//     return status;
//   }
// };

class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    int n = target.size();
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < (1 << n); i++) {
      if (dp[i] == INT_MAX) continue;
      for (auto sticker : stickers) {
        int j = findNextStatus(i, target, sticker);
        dp[j] = min(dp[j], dp[i] + 1);

        // cout << "i: " << bitset<6>(i) << " | j: " << bitset<6>(j) << '\n';
        // cout << "target: " << target << " | sticker: " << sticker << '\n';
        // cout << "dp[i]: " << dp[i] << " | dp[j]: " << dp[j] << '\n';
      }
    }

    return dp[(1 << n) - 1] == INT_MAX ? -1 : dp[(1 << n) - 1];
  }

 private:
  int findNextStatus(int status, const string target, const string s) {
    int n = target.size();
    int new_status = status;

    // 這裏 for 迴圈的 order 很重要！ break 要在對的 loop 裡面！！
    for (auto ch : s) {
      for (int i = 0; i < n; i++) {
        if (((new_status >> i) & 1) != 0) continue;

        // string 的方向跟 bit 是相反過來的，雖然這裡寫反也不會怎樣
        if (ch == target[n - 1 - i]) {
          new_status += (1 << i);
          break;
        }
      }
    }

    //   /* 錯誤的 for loop order */
    //   // for (int i = 0; i < n; i++) {
    //   //   if (((status >> i) & 1) != 0) continue;
    //   //   for (auto ch : s) {
    //   //     if (ch == target[n - 1 - i]) {
    //   //       new_status += (1 << i);
    //   //       break;
    //   //     }
    //   //   }
    //   // }

    return new_status;
  }
};

int main() {
  vector<string> stickers{"with", "example", "science"};
  string target = "thehat";
  //   vector<string> stickers{"ab"};
  //   string target = "b";
  Solution sol;
  int ans = sol.minStickers(stickers, target);
  cout << "ans: " << ans << '\n';
  return 0;
}