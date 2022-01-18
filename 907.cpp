#include "utils.hpp"

/* ref:
    https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution
 */

/* approach 1: Double increasing stacks

    basic idea:
    res = sum(A[i] * f(i))
    where f(i) is the number of subarrays,
    in which A[i] is the minimum.

    真是聰明！

    要小心，一邊 stack 比對是 <，一邊 stack 是 <=
*/
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

int main(int argc, char** argv) {
  std::vector<int> nums{3, 1, 2, 4};
  Solution sol;
  int ans = sol.sumSubarrayMins(nums);
  std::cout << "ans: " << ans << '\n';

  return 0;
}