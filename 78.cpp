#include "utils.hpp"

/*
ref:
https://leetcode.com/problems/subsets/discuss/731215/C%2B%2B-3-approaches%3A-Recursive-Iterative-Bit-Manipulation-Solutions
 */

/* Visit 1
Iterative
*/

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{{}};
    for (int i = 0; i < nums.size(); i++) {
      int size = ans.size();
      for (int j = 0; j < size; j++) {
        vector<int> set = ans[j];
        set.push_back(nums[i]);
        ans.push_back(set);
      }
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  vector<int> nums{1, 2, 3};
  Solution sol;
  vector<vector<int>> ans = sol.subsets(nums);
  print(ans);

  return 0;
}