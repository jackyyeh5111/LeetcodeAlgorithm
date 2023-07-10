
/* More elegant */
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int max_pos = 0;
        for (int i=0; i < N && i <= max_pos; i++)  {
            max_pos = max(i + nums[i], max_pos);
        }
        return max_pos >= N - 1;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int max_pos = 0;
        for (int i = 0; i <= max_pos; i++) {
            if (max_pos >= N - 1)
                return true;
            if (i + nums[i] <= max_pos)
                continue;
            max_pos = i + nums[i];
        }
        return false;
    }
};