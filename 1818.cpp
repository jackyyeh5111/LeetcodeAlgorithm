#include "utils.hpp"

/* ref:
    https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1818-minimum-absolute-sum-difference/
 */

/* Approach 1: Binary search
    Set in C++ is implemented with BST.
 */
class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    constexpr int kMod = 1e9 + 7;
    const int n = nums1.size();
    long ans = 0;
    int gain = 0;
    set<int> s(begin(nums1), end(nums1));
    for (int i = 0; i < n; ++i) {
      const int diff = abs(nums1[i] - nums2[i]);
      ans += diff;
      if (diff <= gain) continue;
      auto it = s.lower_bound(nums2[i]);

      if (it != s.end()) gain = max(gain, diff - abs(*it - nums2[i]));
      if (it != s.begin()) gain = max(gain, diff - abs(*prev(it) - nums2[i]));
    }
    return (ans - gain) % kMod;
  }
};

int main(int argc, char** argv) {
  vector<int> nums1{1, 7, 5};
  vector<int> nums2{2, 3, 5};
  Solution sol;
  int ans = sol.minAbsoluteSumDiff(nums1, nums2);
  std::cout << "ans: " << ans << '\n';

  return 0;
}