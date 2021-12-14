#include <cmath>
#include <iostream>
#include <vector>

/* visit 1 */
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int left = 0;
    for (int right = 1; right < n; right++) {
      if (nums[left] != nums[right]) {
        left++;
        nums[left] = nums[right];
      }
    }

    return left + 1;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{0, 0};
  std::cout << sol.removeDuplicates(nums) << '\n';
  for (int num : nums) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  //   nums = {1};
  //   std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}