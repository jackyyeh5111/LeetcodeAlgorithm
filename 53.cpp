#include <cmath>
#include <iostream>
#include <vector>

/*
     nums:   X X X
  presums: 0 S S S
             i   j

  sum of nums[i, j]: presums[j] - presums[i-1]
 */
class Solution3 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    presums.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }

    divideAndConquer(1, n);
    return max_sum;
  }

 private:
  int max_sum = INT_MIN;
  vector<int> presums;
  void divideAndConquer(int start, int end) {
    if (start > end) return;
    if (start == end) {
      max_sum = max(max_sum, presums[start] - presums[start - 1]);
      return;
    }

    int mid = (start + end) / 2;
    divideAndConquer(start, mid);
    divideAndConquer(mid + 1, end);

    int left_sum = INT_MIN;
    for (int i = mid; i >= start; i--) {
      left_sum = max(left_sum, presums[mid] - presums[i - 1]);
    }

    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= end; i++) {
      right_sum = max(right_sum, presums[i] - presums[mid]);
    }

    max_sum = max(max_sum, left_sum + right_sum);
  }
};

/*
     nums:   X X X
  presums: 0 S S S
             i   j

  sum of nums[i, j]: presums[j] - presums[i-1]
 */
class Solution2 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    presums.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }

    divideAndConquer(1, n);
    return max_sum;
  }

 private:
  int max_sum = INT_MIN;
  vector<int> presums;
  void divideAndConquer(int start, int end) {
    if (start > end) return;
    if (start == end) {
      max_sum = max(max_sum, presums[start] - presums[start - 1]);
      return;
    }

    int mid = (start + end) / 2;
    divideAndConquer(start, mid);
    divideAndConquer(mid + 1, end);

    /* 用雙層 for 浪費時間，只要從中間開始往兩邊展開即可 */
    for (int i = start; i <= mid; i++) {
      for (int j = mid + 1; j <= end; j++) {
        max_sum = max(max_sum, presums[j] - presums[i - 1]);
      }
    }
  }
};

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