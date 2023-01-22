#include "utils.hpp"

/*
ref:
    https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution

  正常思維是先找到各個 subarray b，再去找最小值 min(b)；
  這題反過來想，假設用當前 element 當成最小值，會對應到哪些 subarray

  2 2 [6 3 4 5] 2
         ^
  num_sub_array = 2 * 3

  res += num_sub_array * min_val
  res += (2 * 3) * 3

  prev smaller element => prev smaller or equal element
  next smaller element

  這題要注意的地方就是，若 subarray 有重複 element，需要規定說最左邊 or
最右邊的才算
 */
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    
  }
};

/* approach 2: Double increasing stacks */
class Solution {
 public:
  int sumSubarrayMins(vector<int> A) {
    long res = 0, n = A.size(), mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<pair<int, int>> s1, s2;
    for (int i = 0; i < n; ++i) {
      int count = 1;
      while (!s1.empty() && s1.top().first > A[i]) {
        count += s1.top().second;
        s1.pop();
      }
      s1.push({A[i], count});
      left[i] = count;
    }
    for (int i = n - 1; i >= 0; --i) {
      int count = 1;
      while (!s2.empty() && s2.top().first >= A[i]) {
        count += s2.top().second;
        s2.pop();
      }
      s2.push({A[i], count});
      right[i] = count;
    }
    for (int i = 0; i < n; ++i)
      res = (res + (long)A[i] * left[i] * right[i]) % mod;
    return res;
  }
};

class Solution1 {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    long res = 0;
    constexpr int kMod = 1e9 + 7;
    for (int i = 0; i < arr.size(); ++i) {
      res += helper(arr, i);
    }

    return res % kMod;
  }

  int helper(const vector<int>& arr, int idx) {
    // find the idx of prev smaller or equal element
    int num = arr[idx];
    int prev_idx, next_idx;
    for (prev_idx = idx - 1; prev_idx >= 0; --prev_idx) {
      if (arr[prev_idx] <= num) break;
    }
    // find the idx of next smaller element
    for (next_idx = idx + 1; next_idx < arr.size(); ++next_idx) {
      if (arr[next_idx] < num) break;
    }

    return (idx - prev_idx) * (next_idx - idx) * num;
  }
};

int main(int argc, char** argv) {
  SolutionTest sol;
  std::vector<int> nums{3, 1, 2, 4};
  int ans = sol.sumSubarrayMins(nums);
  std::cout << "ans: " << ans << '\n';

  return 0;
}