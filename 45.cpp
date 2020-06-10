/****************** 2 pointers to record each step ******************/
class Solution {
public:
    // T:O(n)
    int jump(vector<int>& nums) {
        int start = 0; int end = 0; int steps = 0;
        while (end<nums.size()-1) {
            steps++;
            int max_end = end + 1;
            for (int i=start; i<=end; ++i) {
                if (i+nums[i]>=nums.size()-1) return steps;
                max_end = max(i+nums[i], max_end);
            }
            start = end + 1; end = max_end;
        }
        return steps;
    }
};

/****************** back tracking ******************/
/****************** TLE ******************/
class Solution {
public:
    int steps=INT_MAX;
    // worst case T:O(^2)
    int jump(vector<int>& nums)
    {
        // back tracking, assume always can reach last one.
        jump(nums, 0, 0);
        return steps;
    }

    void jump(vector<int>& nums, int current, int maxStep)
    {
        if (current >=nums.size()) return;
        if (current == nums.size()-1) steps=min(maxStep,steps);


        for (int i=nums[current]; i>=1; --i) {
            jump(nums, current+i, maxStep+1);
        }
        return ;
    }
};
