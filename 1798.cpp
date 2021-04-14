/*
    brute force to enumerate all subsets sum, but n is too large that might get TLE.
    T:O(2^n)/S:O(2^n)
    -----
    observation:

    1 can help consecutive integer.
    [1,1,1,4]
    0 1 1 2 1 2 2 3

    with your coins starting from and including 0.
    all coins are positive
    -----
    dp?
    dp[i] indicates max consective starts from zero
    dp[i]=k -> 0~k, nums[i+1]=t
        t~t+k
    dp[i+1]= break if t>k
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins)
    {
        int l=0,r=0;
        sort(coins.begin(),coins.end());
        for (int &coin:coins) {
            if (coin>r+1) break;
            else r+=coin;
        }
        return r+1;
    }
};
