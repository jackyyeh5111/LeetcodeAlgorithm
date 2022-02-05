#include "utils.hpp"

class Solution3 {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    divideAndConquer(nums, target, 0, n - 1);
    return min_len == INT_MAX ? 0 : min_len;
  }

 private:
  int min_len = INT_MAX;
  void divideAndConquer(const vector<int>& nums, const int target, int start,
                        int end) {
    if (start > end) return;
    if (start == end) {
      if (nums[start] >= target) min_len = 1;
      return;
    }

    int mid = (start + end) / 2;
    divideAndConquer(nums, target, start, mid);
    divideAndConquer(nums, target, mid + 1, end);

    int left = mid, right = mid + 1;
    int sum = nums[left] + nums[right];

    while (true) {
      if (right - left + 1 > min_len) return;

      if (sum >= target) {
        min_len = min(min_len, right - left + 1);
        return;
      }

      if (left == start) break;
      if (right == end) break;

      if (nums[left - 1] > nums[right + 1]) {
        left--;
        sum += nums[left];
      } else {
        right++;
        sum += nums[right];
      }

      if (left == start) {
        for (int i = right + 1; i <= end; i++) {
          sum += nums[i];
          if (sum >= target) {
            min_len = min(min_len, right - left + 1);
            return;
          }
        }
      } else {
        for (int i = left - 1; i >= start; i--) {
          sum += nums[i];
          if (sum >= target) {
            min_len = min(min_len, right - left + 1);
            return;
          }
        }
      }
    }
  }
};

/*
2 3 1 2 4 3
    r
  l
*/
class Solution2 {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int ans = INT_MAX;
    int sum = 0;
    for (int right = 0; right < nums.size(); right++) {
      sum += nums[right];
      while (sum >= target) {
        ans = min(ans, right - left + 1);
        sum -= nums[left];
        left++;
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};

/*
    ref:
    https://leetcode.com/problems/minimum-size-subarray-sum/discuss/1375868/C%2B%2B-or-or-Simple-Sliding-Window-Approach
 */

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
  Solution3 sol;

  // int target = 7;
  // std::vector<int> nums{2, 3, 1, 2, 4, 3};
  // std::cout << sol.minSubArrayLen(target, nums) << '\n';

  int target = 11;
  std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << sol.minSubArrayLen(target, nums) << '\n';
  return 0;
}