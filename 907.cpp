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
    int size = A.size();
    std::stack<std::pair<int, int>> s1, s2;
    std::vector<int> left(size), right(size);

    // first increasing stack from left to right.
    for (int i = 0; i < size; i++) {
      int count = 1;
      while (!s1.empty() && A[i] < s1.top().first) {
        count += s1.top().second;
        s1.pop();
      }

      s1.push({A[i], count});
      left[i] = count;
    }

    // second  increasing stack from right to left.
    for (int i = size - 1; i >= 0; i--) {
      int count = 1;
      while (!s2.empty() && A[i] <= s2.top().first) {
        count += s2.top().second;
        s2.pop();
      }

      s2.push({A[i], count});
      right[i] = count;
    }

    long mod = 1e9 + 7;
    long ans = 0;
    for (int i = 0; i < size; i++)
      ans += ((long)A[i] * left[i] * right[i]) % mod;

    return ans;
  }
};

int main(int argc, char** argv) {
  std::vector<int> nums{3, 1, 2, 4};
  Solution sol;
  int ans = sol.sumSubarrayMins(nums);
  std::cout << "ans: " << ans << '\n';

  return 0;
}