#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* visit 1 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 3) return ans;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) return ans;
      int left = i + 1;
      int right = n - 1;

      // item we have seen. skip.
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0)
          left++;
        else if (sum > 0)
          right--;
        else {
          ans.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1]) left++;
          while (left < right && nums[right] == nums[right + 1]) right--;
        }
      }
    }

    return ans;
  }
};

int main(int argc, char** argv) {
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