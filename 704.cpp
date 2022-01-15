#include "utils.hpp"

class Solution2 {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }

    return -1;
  }
};

/* 還要另外檢查 nums[0]，不夠好 */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums[0] == target) return 0;
    int left = 0, right = nums.size();
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid;
      else
        right = mid;
    }

    return -1;
  }
};

int main(int argc, char** argv) {
  vector<int> nums{-1, 0, 3, 5, 9, 12};
  int target;
  target = 9;
  Solution sol;
  int ans = sol.search(nums, target);
  std::cout << "ans: " << ans << '\n';

  return 0;
}