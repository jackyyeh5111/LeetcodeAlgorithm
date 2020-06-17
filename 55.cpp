/******************** Greedy **************************/
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int idx=0; int dst=nums.size()-1;
        int max_step=0;
        while (idx<dst&&max_step<dst) {
            int local_max=0;
            for(int i=idx; i<=max_step; ++i) local_max=max(i+nums[i],local_max);
            if(local_max==max_step&&local_max<dst) return false;
            idx=max_step+1;
            max_step=local_max;
        }
        return true;

    }
};

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i=0;
        for (int reach=0; i<nums.size()&&i<=reach; ++i)
            reach=max(reach, i+nums[i]);
        return i==nums.size();

    }
};
