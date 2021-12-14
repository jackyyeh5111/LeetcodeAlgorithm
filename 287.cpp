#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* ref:
    https://leetcode.com/problems/find-the-duplicate-number/discuss/560089/C%2B%2B-4-different-solutions.-(beats-100-)-Detailed-Explanantion
 */
/* visit 1 */
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[std::abs(nums[i] - 1)] *= -1;
      if (nums[nums[i] - 1] > 0) return nums[i];
    }
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  for (int n : sol.findDisappearedNumbers(nums)) {
    std::cout << n << ' ';
  }
  std::cout << '\n';

  //   intervals = {{1, 3}, {6, 9}};
  //   newInterval = {2, 5};
  //   for (vector<int> ans : sol.insert(intervals, newInterval)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  return 0;
}