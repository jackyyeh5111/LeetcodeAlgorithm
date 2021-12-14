#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
    ref:
    https://leetcode.com/problems/subarray-product-less-than-k/
 */

/* visit 1 */
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int ans = 0, left = 0, right = 0;
    int prod = 1;
    for (int right = 0; right < nums.size(); right++) {
      prod *= nums[right];

      while (prod >= k) {
        prod /= nums[left];
        left++;
      }

      ans += (right - left + 1);
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{10, 5, 2, 6};
  int k = 100;
  std::cout << sol.numSubarrayProductLessThanK(nums, k) << '\n';
  //   for (vector<int> ans : sol.threeSum(nums)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  nums = {1, 1, 1};
  std::cout << sol.numSubarrayProductLessThanK(nums, k) << '\n';
  return 0;
}