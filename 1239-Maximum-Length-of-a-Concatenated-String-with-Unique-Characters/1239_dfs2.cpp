#include "../utils.hpp"

/* TODO 可以提早算出每個 string 的 bit_mask */
class Solution {
 public:
  vector<int> bit_masks;
  int max_len = 0;

  int maxLength(vector<string>& arr) {
    int n = arr.size();
    bit_masks.resize(n);

    for (int i = 0; i < n; i++) {
      for (char ch : arr[i]) {
        bit_masks[i] += 1 << (ch - 'a');
      }
    }

    for (int i = 0; i < n; i++) {
      dfs(0, arr, i);
    }

    return max_len;
  }

  void dfs(int prev_bit_mask, const vector<string>& arr, int idx) {
    int next_bit_mask = prev_bit_mask | bit_masks[idx];
    if (next_bit_mask) return;
    max_len = max(max_len, __builtin_popcount(next_bit_mask));
    int n = arr.size();
    for (int i = idx + 1; i < n; i++) {
      dfs(next_bit_mask, arr, i);
    }
  }
};

int main() {
  //   vector<string> s{"un", "iq", "ue"};
  vector<string> s{"a", "b"};
  //   vector<string> s{"a", "abc", "d", "de", "def"};

  Solution sol;
  int ans = sol.maxLength(s);
  cout << "ans: " << ans << '\n';
  return 0;
}