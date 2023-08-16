#include "utils.hpp"

/* Bit Manipulation */
class Solution5 {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    int p = 1 << n;
    vector<vector<int>> ans(p, vector<int>{});
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) ans[i].push_back(nums[j]);
      }
    }

    return ans;
  }
};

class Solution4 {
 public:
  void findSubsets(const vector<int> &nums, vector<int> subset,
                   vector<vector<int>> &ans, int start_idx) {
    ans.push_back(subset);
    for (int i = start_idx; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      findSubsets(nums, subset, ans, i + 1);
      subset.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{};
    findSubsets(nums, {}, ans, 0);
    return ans;
  }
};

/* Wrong
  這樣做不可行，因為 {1, 3} 無法包含在 subset 裡面！
*/
class Solution3 {
 public:
  void findSubsets(const vector<int> &nums, vector<int> subset,
                   vector<vector<int>> &ans, int start_idx) {
    if (start_idx == size_) return;

    subset.push_back(nums[start_idx]);
    ans.push_back(subset);
    findSubsets(nums, subset, ans, start_idx + 1);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    size_ = nums.size();
    vector<vector<int>> ans{{}};
    for (int i = 0; i < size_; i++) {
      findSubsets(nums, {}, ans, i);
    }

    return ans;
  }

 private:
  int size_;
};

/*
ref:
  https://leetcode.com/problems/subsets/discuss/731215/C%2B%2B-3-approaches%3A-Recursive-Iterative-Bit-Manipulation-Solutions
 https://hackmd.io/Vph3zrY5T_CbteFyS1QUgA
 */

/* Visit 2
  Revursive
 */
class Solution2 {
 public:
  void findSubsets(const vector<int> &nums, vector<int> subset,
                   vector<vector<int>> &ans, int start_idx) {
    if (start_idx == nums.size()) return;

    findSubsets(nums, subset, ans, start_idx + 1);

    subset.push_back(nums[start_idx]);
    ans.push_back(subset);

    findSubsets(nums, subset, ans, start_idx + 1);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{{}};
    findSubsets(nums, {}, ans, 0);

    return ans;
  }
};

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
  Solution5 sol;
  vector<int> nums{1, 2, 3};
  vector<vector<int>> ans = sol.subsets(nums);
  print(ans);

  return 0;
}