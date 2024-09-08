class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int base = 0; base < nums.size() - 2; base++) {
            int left = base + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[base];
                
                // update answer
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;

                if (sum < target) left++;
                else right--;
            }
        }
        return ans;
    }
};

/* 
    target: 1
    modified target: 5
    -4 XXXXXX
     B   
       l    r
 */