#include "utils.hpp"

/* 
    TODO:
        understand linear solution
        https://leetcode.com/problems/subsequence-with-the-minimum-score/solutions/3174041/right-and-left-o-n/
 */

/*
    case 1:
        s = abc, t = abc
    case 2:
        s = abc, t = d

    t: xxx [yyy] zzz
         i       j
    Remove yyy and xxxzzz is a subsequence of s.

    lefts[i]: the shortest prefix of s contains t[0:i]
    rights[j]: the shortest suffix of s contains t[j:n-1]

    lefts[i] < rights[j]

    1. Create lefts and rights array.
    2. Use bs to find the length of [yyy].
    3. Check xxxzzz is a subsequence of s.
 */
class Solution {
 public:
  vector<int> lefts, rights;
  int minimumScore(string s, string t) {
    int t_n = t.size();
    int s_n = s.size();
    lefts.resize(t_n, INT_MAX);
    rights.resize(t_n, INT_MIN);

    // Create left and right array.
    int idx = 0;
    for (int i = 0; i < s_n; ++i) {
      if (t[idx] == s[i]) {
        lefts[idx] = i;
        ++idx;
      }
      if (idx == t_n) break;
    }
    idx = t_n - 1;
    for (int i = s_n - 1; i >= 0; --i) {
      if (t[idx] == s[i]) {
        rights[idx] = i;
        --idx;
      }
      if (idx == -1) break;
    }

    // Use bs to find the length
    int left = t_n > s_n ? t_n - s_n : 0;
    int right = t_n;
    while (left != right) {
      int middle = left + (right - left) / 2;
      // left array [0, middle]
      // right array  (middle, n-1]
      if (!isSubsequence(s, t, middle))
        left = middle + 1;
      else
        right = middle;
    }
    return left;
  }

  bool isSubsequence(string s, string t, int rm_len) {
    int t_n = t.size();
    if (rm_len == t_n) return true;
    if (rights[rm_len] != INT_MIN) return true;
    if (lefts[t_n - 1 - rm_len] != INT_MAX) return true;

    for (int i = 0; i < t_n - rm_len - 1; ++i) {
      if (lefts[i] < rights[i + rm_len + 1]) return true;
    }
    return false;
  }
};

int main(int argc, char** argv) {
  string s = "ab";
  string t = "az";
  Solution sol;
  int ans = sol.minimumScore(s, t);
  std::cout << "ans: " << ans << '\n';

  return 0;
}