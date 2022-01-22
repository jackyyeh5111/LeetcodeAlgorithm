#include "utils.hpp"

/*

N [          ]
Y N [      ] N

如果我第一家偷，最後一家肯定不偷，那就dp到 [0, -1]
如果第一家不偷，後面就用正常的雙狀態 dp
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    // case 1
    int temp = max(nums[1], nums[2]);
    int temp2 = nums[1];
    for (int i = 3; i < n; i++) {
      int new_temp = max(temp, temp2 + nums[i]);
      temp2 = temp;
      temp = new_temp;
    }

    int case1_ans = max(temp, temp2);

    // case 2
    temp = nums[0];
    temp2 = nums[0];
    for (int i = 2; i < n - 1; i++) {
      int new_temp = max(temp, temp2 + nums[i]);
      temp2 = temp;
      temp = new_temp;
    }

    int case2_ans = max(temp, temp2);

    return max(case1_ans, case2_ans);
  }
};

int main() {
  std::vector<int> nums{2, 3, 2};
  Solution sol;
  int ans = sol.rob(nums);
  std::cout << "ans: " << ans << '\n';

  nums = std::vector<int>{1, 2, 3, 1};
  ans = sol.rob(nums);
  std::cout << "ans: " << ans << '\n';

  return 0;
}