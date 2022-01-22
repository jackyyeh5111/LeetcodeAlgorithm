#include "utils.hpp"

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    /*
      dp[i]: consider nums[0..i], largest divisble subset that ends with
      nums[i].
    */
    vector<int> dp(n, 0);
    vector<int> prev(n, -1); // 新增 prev 紀錄前一個 num

    int max_subset_idx = -1, max_subset_num = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          int subset_num = dp[j] + 1;
          if (subset_num > dp[i]) {
            dp[i] = subset_num;
            prev[i] = j;

            if (subset_num > max_subset_num) {
              max_subset_num = subset_num;
              max_subset_idx = i;
            }
          }
        }
      }
    }

    if (max_subset_idx == -1) return {nums[0]};

    vector<int> ans;
    int idx = max_subset_idx;
    while (idx != -1) {
      ans.push_back(nums[idx]);
      idx = prev[idx];
    }

    return ans;
  }
};

int main() {
  vector<int> nums{1, 2, 4, 8};
  Solution sol;
  vector<int> ans = sol.largestDivisibleSubset(nums);
  print(ans);
  return 0;
}