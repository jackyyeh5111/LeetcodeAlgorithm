#include "utils.hpp"

/* 
  Omit max operation.
 */
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];

        int ans1, ans2;
        // rob 1st
        int d1 = 0, d2 = nums[0];
        for (int i = 1; i < N - 1 ; ++i) {
            int tmp = max(d1 + nums[i], d2);
            d1 = d2;
            d2 = tmp;
        }
        ans1 = d2; // Not required max(d1, d2)

        d1 = 0;
        d2 = nums[1];
        for (int i = 2; i < N; ++i) {
            int tmp = max(d1 + nums[i], d2);
            d1 = d2;
            d2 = tmp;
        }
        ans2 = d2;
        return max(ans1, ans2);
    }
};

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

    // select the first hoouse
    int temp0 = nums[0];
    int temp1 = temp0;
    for (int i = 2; i <= n - 2; ++i) {
      int temp = temp1;
      temp1 = max(temp1, temp0 + nums[i]);
      temp0 = temp;
    }
    int select_first = max(temp1, temp0);

    // select the second hoouse
    temp0 = 0;
    temp1 = nums[1];
    for (int i = 2; i <= n - 1; ++i) {
      int temp = temp1;
      temp1 = max(temp1, temp0 + nums[i]);
      temp0 = temp;
    }
    int select_second = max(temp1, temp0);

    return max(select_first, select_second);
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