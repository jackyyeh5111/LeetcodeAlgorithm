class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i=0;
        for (const int &num:nums) {
            if (i<2||num>nums[i-2])
                nums[i++]=num;
        }
        return i;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        // remove duplicate AT MOST TWICE
        // use 2 pointer, say i j
        // i indicates the value we checked which is not duplicated over twice.
        // j travel the vector all the way.
        // use another variables to record current value and its frequency.
        if (nums.size()==0) return 0;
        int i=1; int val=nums[0]; int counter=1;
        for (int j=1; j<nums.size(); ++j) {
            if (nums[j]==val) {
                if (counter<2) {nums[i++]=nums[j]; counter++;}
            }
            else { counter=1; val=nums[i++]=nums[j]; }
        }
        return i;
    }
};
