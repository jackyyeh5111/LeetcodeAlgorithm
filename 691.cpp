#include "utils.hpp"

/*
  ref: https://hackmd.io/Y5KprctBRcCZW2faCMv5GA
  
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

class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    int n = target.size();
    int num_status = 1 << n;
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    for (auto sticker : stickers) {
      for (int i = 0; i < num_status; i++) {
        if (dp[i] == INT_MAX) continue;
        int j = findNextStatus(i, sticker, target);
        dp[j] = min(dp[j], dp[i] + 1);
      }
    }

    return dp[num_status - 1] == INT_MAX ? -1 : dp[num_status - 1];
  }

  int findNextStatus(int status, string sticker, string target) {
    int size = target.size();
    for (char ch : sticker) {
      for (int i = 0; i < size; i++) {
        if ((status >> i) & 1) continue;

        /*
          string 的方向跟 bit 是相反過來的，雖然這裡寫反也不會怎樣
          if (ch == target[n - 1 - i]) {
         */
        if (ch == target[i]) {
          status += (1 << i);
          break;
        }
      }
    }

    /* 錯誤的 for loop order
       Character cannot be used more than once!
    */
    //   // for (int i = 0; i < n; i++) {
    //   //   if (((status >> i) & 1) != 0) continue;
    //   //   for (auto ch : s) {
    //   //     if (ch == target[n - 1 - i]) {
    //   //       new_status += (1 << i);
    //   //       break;
    //   //     }
    //   //   }
    //   // }

    return status;
  }
};

int main() {
  vector<string> stickers{"with", "example", "science"};
  string target = "thehat";
  Solution sol;
  int ans = sol.minStickers(stickers, target);
  cout << "ans: " << ans << '\n';
  return 0;
}