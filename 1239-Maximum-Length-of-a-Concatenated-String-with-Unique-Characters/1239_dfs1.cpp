#include "utils.hpp"

/* Approach 3: dfs (value 不用會傳) */
class Solution2 {
 public:
  int maxLength(vector<string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      dfs(0, arr, i);
    }

    return max_len;
  }

 private:
  int max_len = 0;
  void dfs(int prev_bit_mask, const vector<string>& arr, int idx) {
    for (int i = idx; i < arr.size(); i++) {
      bool duplicate = false;
      int new_bit_mask = 0;
      for (char ch : arr[i]) {
        int new_bit = (1 << (ch - 'a'));
        if ((new_bit_mask & new_bit) || (prev_bit_mask & new_bit)) {
          //   cout << arr[i] << " | ch: " << ch << '\n';
          duplicate = true;
          break;
        }

        new_bit_mask += new_bit;
      }

      if (duplicate) continue;

      //   cout << "prev_bit_mask: " << prev_bit_mask << '\n';
      //   cout << "new_bit_mask: " << new_bit_mask << '\n';
      max_len = max(max_len, __builtin_popcount(prev_bit_mask | new_bit_mask));

      dfs(prev_bit_mask | new_bit_mask, arr, i + 1);
    }
  }
};

/* Approach 2: DP

    // 這題沒辦法用 dp >"<
    ex:
        "ab" | "bc" | "d"
        1100 | 0110 | 0001

    # definition
    dp[i]: the maximum length of string that is formed by arr[0..i]
           which has unique characters.

    # transfer function
    dp[i] = dp[i-1] + arr[i].size() // 錯！
*/

/*
    Approach 1: DFS
    用 26 bit mask

    algo:
    1. Iterate through each string s in arr. Add it in bit mask if valid.
       We can use & operation to check if s is valid.
    2. ...

    Approach 1 的 dfs function 根本不是 dfs 啊！！ 少一個 for loop
 */

class Solution {
 public:
  int maxLength(vector<string>& arr) {
    int max_len = 0;
    for (int i = 0; i < arr.size(); i++) {
      int bit_mask = dfs(0, arr, i);
      max_len = max(max_len, __builtin_popcount(bit_mask));
    }

    // int bit_mask = dfs(0, arr, 0);
    // cout << "# 1's in bit_mask: " << __builtin_popcount(bit_mask) << '\n';

    return max_len;
  }

 private:
  /*  bit_mask 不要用回傳的，這樣太麻煩！ 見 Approach 3 */
  int dfs(int bit_mask, const vector<string>& arr, int idx) {
    if (idx == arr.size()) return bit_mask;

    bool duplicate = false;
    int new_bit_mask = 0;
    for (char ch : arr[idx]) {
      int new_bit = (1 << (ch - 'a'));
      if ((new_bit_mask & new_bit) || (bit_mask & new_bit)) {
        cout << arr[idx] << " | ch: " << ch << '\n';
        duplicate = true;
        break;
      }

      new_bit_mask += new_bit;
    }

    if (duplicate) return bit_mask;

    int max_len = 0;
    for (int i = idx + 1; i < arr.size(); i++) {
      int bit_mask = dfs(0, arr, i);
      max_len = max(max_len, __builtin_popcount(bit_mask));
    }
    // 太麻煩不想寫～
    // ...

    dfs(bit_mask | new_bit_mask, arr, idx + 1);
  }

  /*
    這樣也是錯的，沒考慮到 case:
    ["a", "abc", "d", "de", "def"]
   */
  //   int dfs(int bit_mask, const vector<string>& arr, int idx) {
  //     if (idx == arr.size()) return bit_mask;

  //     bool duplicate = false;
  //     int new_bit_mask = 0;
  //     for (char ch : arr[idx]) {
  //       int new_bit = (1 << (ch - 'a'));
  //       if ((new_bit_mask & new_bit) || (bit_mask & new_bit)) {
  //         cout << arr[idx] << " | ch: " << ch << '\n';
  //         duplicate = true;
  //         break;
  //       }

  //       new_bit_mask += new_bit;
  //     }

  //     if (duplicate) new_bit_mask = 0;

  //     return dfs(bit_mask | new_bit_mask, arr, idx + 1);
  //   }

  /* 這裡 dfs 有個問題，沒考慮到一個子字串內會有重複的字元
     ex:
        ["aa", "bc"]
  */
  //   int dfs(int bit_mask, const vector<string>& arr, int idx) {
  //     if (idx == arr.size()) return bit_mask;

  //     int new_bit_mask = 0;
  //     for (char ch : arr[idx]) {
  //       new_bit_mask += (1 << (ch - 'a'));
  //     }

  //     if (bit_mask & new_bit_mask) new_bit_mask = 0;

  //     return dfs(bit_mask | new_bit_mask, arr, idx + 1);
  //   }
};

int main() {
  vector<string> s{"un", "iq", "aa"};
  //   vector<string> s{"a", "abc", "d", "de", "def"};

  Solution2 sol;
  int ans = sol.maxLength(s);
  cout << "ans: " << ans << '\n';
  return 0;
}