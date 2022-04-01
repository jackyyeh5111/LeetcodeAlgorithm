#include "utils.hpp"

/*
    ref:
    https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)

  Approach: binary + presum

     nums:   1 2
  presums: 0 1 3
               i   j
  range sum of [i, j]: presums[j] - presums[i-1]

  XXXXXXXX
   i   j

  presums[j] - presums[i-1] >= target ==>
  presums[j] >= presums[i-1] + target ==>
  presums[j] - target >= presums[i-1]

  Time complexity: O(nlogn)
 */
class Solution5 {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> presums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      presums[i] = presums[i - 1] + nums[i - 1];
    }

    int res = INT_MAX;
    for (int j = n; j >= 1 && presums[j] >= target; j--) {
      int i = upper_bound(presums.begin(), presums.end(), presums[j] - target) -
              presums.begin();
      res = min(res, j - i + 1);
    }

    return res == INT_MAX ? 0 : res;
  }
};

class Solution4 {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> presums;
    presums.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      presums[i] = presums[i - 1] + nums[i - 1];
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
      auto it = lower_bound(presums.begin() + i, presums.end(),
                            presums[i - 1] + target);
      if (it != presums.end()) {
        int len = it - (presums.begin() + i - 1);
        ans = min(ans, len);
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};

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

      /* 這想法根本就是錯的！
        case:

        2 2 2 2 1 1000
          l   r

        如此永遠走不到1000，只會一直走左邊
       */
      if (nums[left - 1] > nums[right + 1]) {
        left--;
        sum += nums[left];
        cout << "left sum: " << sum << '\n';
      } else {
        right++;
        sum += nums[right];
        cout << "right sum: " << sum << '\n';
      }
    }

    if (left == start) {
      for (int i = right + 1; i <= end; i++) {
        sum += nums[i];
        cout << "aaa sum: " << sum << '\n';
        if (sum >= target) {
          min_len = min(min_len, i - left + 1);
          return;
        }
      }
    } else {
      for (int i = left - 1; i >= start; i--) {
        sum += nums[i];
        cout << "bbb sum: " << sum << '\n';
        if (sum >= target) {
          min_len = min(min_len, right - i + 1);
          return;
        }
      }
    }
  }
};

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, sum = 0;
    int res = INT_MAX;
    while (right < nums.size()) {
      sum += nums[right];
      while (sum >= target) {
        res = min(res, right - left + 1);
        left++;
        sum -= nums[left];
      }

      right++;
    }

    return res == INT_MAX ? 0 : res;
  }
};

int main(int argc, char** argv) {
  Solution4 sol;

  int target = 11;
  std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << sol.minSubArrayLen(target, nums) << '\n';

  target = 4;
  nums = std::vector<int>{1, 4, 4};
  std::cout << sol.minSubArrayLen(target, nums) << '\n';
  return 0;
}