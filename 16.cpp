class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX / 2;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int num = binary_search(nums, i, j, target);
                int sum = nums[i] + nums[j] + num;
                if (abs(sum - target) < abs(min_diff))
                    min_diff = sum - target;
            }
        }
        return target + min_diff;
    }
    int binary_search(const vector<int>& nums, int i, int j, int target) {
        int left = j + 1;
        int right = nums.size() - 1;
        target -= (nums[i] + nums[j]);
        while (left < right) {
            int mid = right - (right - left) / 2;
            // left: [left, mid)
            // right: [mid, right]

            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        if (left == nums.size() - 1 || abs(nums[left] - target) < abs(nums[left+1] - target))
            return nums[left];
        return nums[left+1];
    }
};

/* 
    target: 1
    modified target: 6
    -4 -1 1 2
     i  j  
          l r
 */