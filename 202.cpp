#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* Ref:
    https://hackmd.io/qX6k3iZ9SP6GoqeBS6hxrA
 */
/* Visit 1 */
class Solution {
 public:
  int sumSquare(int n) {
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }

    return sum;
  }
  bool isHappy(int n) {
    int slow = n, fast = n;
    while (true) {
      slow = sumSquare(slow);
      fast = sumSquare(sumSquare(fast));

      if (slow == 1 || fast == 1) return true;
      if (slow == fast) return false;
    }
  }
};

int main(int argc, char **argv) {
  Solution sol;
  std::vector<int> nums{-1, 0, 1, 2, -1, -4};
  //   std::cout << sol.removeDuplicates(nums) << '\n';
  for (vector<int> ans : sol.threeSum(nums)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  //   nums = {1};
  //   std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}