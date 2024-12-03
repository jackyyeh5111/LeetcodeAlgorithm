#include "utils.hpp"

/*
    ref:
    https://hackmd.io/FYtK5m3IShaIFGOKLZSANg
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624390/C%2B%2B-Brute-Force-To-Optimized-SolutionO(N)-Time-or-W-Explanation
 */

/* Approach 4: bitset  */
class Solution4 {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    std::bitset<10001> bits(1);
    for (const int& num : nums) {
      bits |= bits << num;
      if (bits[sum / 2]) return true;
    }

    return false;
  }
};

/* Approach 3: DP - Space Optimized 
    arr: 1 2 3 4
    
           0 1 2 3 4 5
    {1}    T T F F F F
    {1 2}  T T T T F F    
    {1 2 3}

    sum: 10
    target: 5
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        
        int target = sum / 2;
        vector<bool> dp(target+1);
        dp[0] = true;
        for (int num : nums) {
            vector<bool> next_dp = dp;
            for (int i = num; i <= target; i++) {
                if (dp[i-num])
                    next_dp[i] = true;
            }
            dp = std::move(next_dp);
        }
        return dp[target];
    }
};

/* Approach 2: DP */
// 矩陣可以節省 space，只要 (n+1) * sum / 2 即可，不需要 (n+1) * sum
class Solution2 {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    sum /= 2;
    nums.insert(nums.begin(), 0);  // dummy
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // init dp matrix
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= sum; j++) {
        if (nums[i] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
      }
    }

    return dp[n][sum];
  }
};

/* Approach 1: Brute Force - Recursion */
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum % 2 == 0 && dfs(nums, sum / 2, 0);
  }

  bool dfs(const vector<int>& nums, int sum, int idx) {
    if (sum == 0) return true;
    if (idx >= nums.size() || sum < 0) return false;
    return dfs(nums, sum - nums[idx], idx + 1) || dfs(nums, sum, idx + 1);
  }
};

int main(int argc, char** argv) {
  SolutionTest sol;
  bool ans;
  vector<int> nums{1, 2, 5};
  ans = sol.canPartition(nums);
  std::cout << "ans: " << ans << '\n';

  // vector<int> nums2{1, 5, 11, 5};
  // ans = sol.canPartition(nums2);
  // std::cout << "ans: " << ans << '\n';

  // vector<int> nums3{1, 2, 3, 5};
  // ans = sol.canPartition(nums3);
  // std::cout << "ans: " << ans << '\n';

  return 0;
}