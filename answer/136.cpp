/***** Second Visit *****/
/*
    single number with constraint: T:O(n)/S:O(1)
    use bit operation: x^x=0, x^0=x;
*/
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ans=0;
        for(int num:nums) ans^=num;
        return ans;
    }
};

/***** First Visit *****/
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
