#include <cmath>
#include <iostream>
#include <vector>

/*
    ref:
    https://leetcode.com/problems/minimum-size-subarray-sum/discuss/1375868/C%2B%2B-or-or-Simple-Sliding-Window-Approach
 */

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = n + 1;
    int left = 0;
    int right = 0;
    int sum = 0;
    while (right < n) {
      while (right < n && sum < target) {
        sum += nums[right];
        right++;
      }
      while (left <= right && sum >= target) {
        ans = std::min(ans, right - left);
        sum -= nums[left];
        left++;
      }

      if (ans == 1) return 1;
    }

    return ans == n + 1 ? 0 : ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;

  int target = 7;
  std::vector<int> nums{2, 3, 1, 2, 4, 3};
  std::cout << sol.minSubArrayLen(target, nums) << '\n';

  target = 4;
  nums = {1, 4, 4};
  std::cout << sol.minSubArrayLen(target, nums) << '\n';
  return 0;
}