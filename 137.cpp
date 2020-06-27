/*
sorting: T:O(nlogn)+O(n) S:O(1)
----------------------
counting sort: T:O(n), S:O(n)
----------------------
Request: T:O(n), S:O(1), but we need extra space to save status of each number
this conflict first give us a thought... bit operation! we have 32 space to utilize
so base on bit op, we now can iterate over each num and calculate the frequency of EACH BIT,
than mod the target to see which bit is not 0.

-> vector<int> (32,0) represents 32 bit, which is O(1)
-> 3 numbers for us to save status for 1->2->3->1->2->...,
   and see the bit saved in 1 in the end.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ones=0, twos=0, threes=0;
        for (auto num: nums){
            twos=twos|(ones&num);
            ones=ones^num;
            threes=twos&ones;
            ones=ones&~threes;
            twos=twos&~threes;
        }
        return ones;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int> statistic(32,0);
        for (auto num:nums){
            for (int i=31; i>=0; --i) {
                if((1&num)) statistic[i]++;
                num=num>>1;
            }
        }
        int ans=0;
        for (int i=0; i<32; ++i){
            int res=statistic[i]%3;
            ans=ans<<1;
            if (res) ans+=1;
        }
        return ans;
    }
};
