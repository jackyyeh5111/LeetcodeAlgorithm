#include "utils.hpp"

class Solution3 {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> ans{{}};
    int start_new_num_idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        vector<int> subset{i - start_new_num_idx + 1, nums[i]};
        ans.push_back(subset);
      } else {
        int size = ans.size();
        for (int j = 0; j < size; j++) {
          vector<int> subset = ans[j];
          subset.push_back(nums[i]);
          ans.push_back(subset);
        }
        start_new_num_idx = i;
      }
    }

    return ans;
  }
};

/* Visit 2
  ref: https://leetcode.wang/leetCode-90-SubsetsII.html
  当有重复数字的时候，我们只考虑上一步的新解，算法中用一个指针保存每一步的新解开始的位置即可。
 */
class Solution2 {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> ans{{}};

    int prev_start_idx;
    for (int i = 0; i < nums.size(); i++) {
      int start_idx = i > 0 && nums[i] == nums[i - 1] ? prev_start_idx : 0;
      prev_start_idx = ans.size();

      int size = ans.size();
      for (int j = start_idx; j < size; j++) {
        vector<int> subset = ans[j];
        subset.push_back(nums[i]);
        ans.push_back(subset);
      }
    }

    return ans;
  }
};

// wrong for loop 順序錯誤
// class Solution2 {
//  public:
//   vector<vector<int>> subsetsWithDup(vector<int> &nums) {
//     std::sort(nums.begin(), nums.end());

//     vector<vector<int>> ans{{}};
//     for (int i = 0; i < nums.size(); i++) {
//       int size = ans.size();
//       int start_idx = i;
//       for (int j = 0; j < size; j++) {
//         if (i > start_idx && nums[i] == nums[i - 1]) continue;
//         vector<int> subset = ans[j];
//         subset.push_back(nums[i]);
//         ans.push_back(subset);
//       }
//     }

//     return ans;
//   }
// };

/* Visit 1
ref:
https://medium.com/@ChYuan/leetcode-90-subsets-ii-%E5%BF%83%E5%BE%97-medium-f6eaa6f6ee23
 */

class Solution {
 public:
  vector<vector<int>> ans;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    generateSubs(nums, {}, 0);
    return ans;
  }

  void generateSubs(const vector<int> &nums, vector<int> subset, int begin) {
    ans.push_back(subset);
    for (int i = begin; i < nums.size(); i++) {
      if (i > begin && nums[i] == nums[i - 1]) continue;
      subset.push_back(nums[i]);
      generateSubs(nums, subset, i + 1);
      subset.pop_back();
    }
  }
};

int main(int argc, char **argv) {
  vector<int> nums{1, 2, 2};
  Solution3 sol;
  vector<vector<int>> ans = sol.subsetsWithDup(nums);
  print(ans);

  return 0;
}