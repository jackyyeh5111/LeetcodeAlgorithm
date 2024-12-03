class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int occur_cnt = 0;
        int prev = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (right == 0 || nums[right] != prev) {
                occur_cnt = 1; // first time occurance
            }
            else {
                occur_cnt++;
            }

            prev = nums[right]; // important! Do this before swap
            if (occur_cnt <= 2) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
        return left;
    }
};

/*          
    occur_time = 1
            v
    1 1 2 2 3 2 1
                ^
 */