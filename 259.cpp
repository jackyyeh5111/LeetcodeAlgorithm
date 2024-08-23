class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int base = 0; base < nums.size(); base++) {
            int left = base + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[base] + nums[left] + nums[right];
                if (sum >= target)
                    right--;
                else {
                    ans += right - left;
                    left++;
                }
            }
        }
        return ans;
    }
};

/* 
    clarification:
    1. duplicate element should be counted as well
    2. len(nums) < 3, return 0
    
    target: 2
    nums: 1 0 -2 3
      => -2 0 1 3 4
          b
            l   r

    [-2 0 1]
    [-2 0 3]
    The amount of combination containing [-2 0] is 2 = r - l
 */