class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        /*
            constrain: S:O(1).
            brute force: T:O(n^2)
            ------------------------
            use int bitwise bin for saving each num, if there's some digits%2!=0
            then it belongs to the single one.
        */
        int ans=0;
        for (int num:nums) ans=ans^num;
        return ans;
    }
};
