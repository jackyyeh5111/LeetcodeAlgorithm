
#include "utils.hpp"

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));

    // init dp matrix
    for (int i = 0; i < n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum / 2; j++) {
        if (nums[i - 1] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
      }
    }

    return dp[n][sum / 2];
  }
};

// set::equal_elements
#include <iostream>
#include <set>

class Solution5 {
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

      if (it != s.end()) {
        std::cout << "aaa\n";
        gain = max(gain, diff - abs(*it - nums2[i]));
      }

      if (it != s.begin()) gain = max(gain, diff - abs(*prev(it) - nums2[i]));
    }
    return (ans - gain) % kMod;
  }
};

// prev example
#include <algorithm>  // std::for_each
#include <iostream>   // std::cout
#include <iterator>   // std::next
#include <list>       // std::list

void foo(int* t) {
  std::cout << "foo &t: " << &t << '\n';
  return;
}
int main() {
  int n = 5;
  int* a = &n;
  std::cout << "&a: " << &a << '\n';
  foo(a);
  return 0;
}
