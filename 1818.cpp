#include "utils.hpp"

/* ref:
  https://hackmd.io/uq_gbHtSTpG36PvW7VE7ww
  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1818-minimum-absolute-sum-difference/
 */

/* Approach 2: Binary search with std::set
    Set in C++ is implemented with BST.

    Elements in nums1 may be not unique. With set, we can do binary search  more
   effciently.
 */
class Solution2 {
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
      auto it = s.lower_bound(nums2[i]);  // binary search

      if (it != s.end()) gain = max(gain, diff - abs(*it - nums2[i]));
      if (it != s.begin()) gain = max(gain, diff - abs(*prev(it) - nums2[i]));
    }
    return (ans - gain) % kMod;
  }
};

/* Approach 1: Binary search
 */
class Solution1 {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();

    constexpr int kMod = 1e9 + 7;
    vector<int> sort_nums1 = nums1;
    sort(sort_nums1.begin(), sort_nums1.end());

    long sum = 0;
    int gain = 0;
    for (int i = 0; i < n; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      sum += diff;
      if (diff <= gain) continue;

      auto it = lower_bound(sort_nums1.begin(), sort_nums1.end(), nums2[i]);
      if (it != sort_nums1.end()) gain = max(diff - abs(*it - nums2[i]), gain);
      if (it != sort_nums1.begin())
        gain = max(diff - abs(*prev(it) - nums2[i]), gain);
    }
    return (sum - gain) % kMod;
  }
};

int main(int argc, char** argv) {
  vector<int> nums1{1, 7, 5};
  vector<int> nums2{2, 3, 5};
  SolutionTest sol;
  int ans = sol.minAbsoluteSumDiff(nums1, nums2);
  std::cout << "ans: " << ans << '\n';

  return 0;
}