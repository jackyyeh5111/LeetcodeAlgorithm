#include <cmath>
#include <iostream>
#include <vector>

/* Divide and conquer
    ref:
    https://leetcode.com/problems/maximum-subarray/discuss/540951/C%2B%2B-divide-and-conquer-solution
*/

class Solution {
 public:
  std::vector<int> arr;

  int sumCross(int left, int right, int mid) {
    // left sum
    int sum = arr[mid];
    int sum_left = arr[mid];
    for (int i = mid - 1; i >= left; i--) {
      sum += arr[i];
      sum_left = std::max(sum_left, sum);
    }

    // right sum
    sum = arr[mid + 1];
    int sum_right = arr[mid + 1];
    for (int i = mid + 2; i < right; i++) {
      sum += arr[i];
      sum_right = std::max(sum_right, sum);
    }

    return sum_left + sum_right;
  }

  int helper(int left, int right) {
    if (left >= right) {
      return arr.at(left);
    }

    int mid = (left + right) / 2;
    int sum_left = helper(left, mid);
    int sum_right = helper(mid + 1, right);
    int sum_cross = sumCross(left, right, mid);

    return std::max(sum_cross, std::max(sum_left, sum_right));
  }

  int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    arr = nums;
    return helper(0, n - 1);
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << sol.maxSubArray(nums) << '\n';

  nums = {1};
  std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}