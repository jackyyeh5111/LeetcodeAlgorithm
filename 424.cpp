#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

/* visit 1
   ref:
   https://leetcode.com/problems/longest-repeating-character-replacement/discuss/934637/Clear-concise-C%2B%2B-solution-(Sliding-window-better-than-99-time-O(n))

    k = 1
      A A B C
        l   r
 */

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    unordered_map<int, int> um;
    int r = 0;
    int l = 0;
    int max_char_freq = 0;
    int ans = 0;

    while (r < n) {
      um[s[r]]++;
      max_char_freq = max(max_char_freq, um[s[r]]);
      r++;

      // Note that here is not a while loop. Because our target is "longest"
      // substring. Thus we can keep the longest window(right - left) here.

      /*
        The window size increases only when maxFrequency finds a new maximum.
        For this, we always want the following condition to hold true:
          window_size - max_char_freq <= k
       */
      if (r - l - max_char_freq > k) {
        um[s[l]]--;
        l++;
      }
    }

    return r - l;
  }
};

int main(int argc, char** argv) {
  Solution sol;

  std::string s = "AABABBA";
  int k = 1;
  std::cout << sol.characterReplacement(s, k) << '\n';

  return 0;
}