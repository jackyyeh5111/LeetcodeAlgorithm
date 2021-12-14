#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/* visit 1 */
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int right;
    for (right = 0; right < n; right++) {
      if (nums[right] >= 0) break;
    }

    int left = right - 1;
    int idx = 0;
    while (left >= 0 || right < n) {
      if (left < 0) {
        while (right < n) {
          ans[idx++] = nums[right] * nums[right];
          right++;
        }
      } else if (right >= n) {
        while (left >= 0) {
          ans[idx++] = nums[left] * nums[left];
          left--;
        }
      } else if (nums[left] + nums[right] < 0) {
        ans[idx++] = nums[right] * nums[right];
        right++;
      } else {
        ans[idx++] = nums[left] * nums[left];
        left--;
      }
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{-4, -1, 0, 3, 10};
  //   std::cout << sol.sortedSquares(nums) << '\n';
  for (int num : sol.sortedSquares(nums)) {
    std::cout << num << ' ';
  }
  std::cout << '\n';

  //   nums = {1};
  //   std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}