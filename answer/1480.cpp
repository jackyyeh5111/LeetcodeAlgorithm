class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        int s=0;
        for (int &num:nums){
            s+=num;
            num=s;
        }
        return nums;
    }
};
