#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* Ref:
  https://leetcode.com/problems/merge-intervals/discuss/600013/C%2B%2B-solution-with-detailed-explanation
 */

/* visit 1 */
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) return intervals;
    std::sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans{intervals[0]};
    int j = 0;
    for (int i = 1; i < n; i++) {
      if (ans[j][1] >= intervals[i][0]) {
        ans[j][1] = std::max(ans[j][1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
        j++;
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