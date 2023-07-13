
/* More elegant */
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int max_pos = 0;
        
        /* 
            Let's say "i > max_pos", the game cannot continue.
            
            example:
                nums: [1 0 5 1]
                           ^
                max_pos: 1

                *Standing on index 2, but the max_pos of preceding elements can jump to is 1.
                *It only happens when number zero exists in the array.
         */
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