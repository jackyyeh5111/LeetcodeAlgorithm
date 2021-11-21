/*
    brute force:
    iterate over all possible pairs i,j and do comparison
    T:O(n^2)/S:O(1)
    -----
    First: how to verify if 2 nums form a power of 2.
    long (num1&num2 & num1&num2-1) == 0
    101
    011
    -----
    Check constraints and see if we can utilize the afordable boundary.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int countPairs(vector<int>& deliciousness) 
    {
        int mod=pow(10,9)+7, ans=0;
        unordered_map<int,int> m;
        for (int d:deliciousness) {
            for (int i=0; i<22; ++i) {
                if (m.count((1<<i)-d)) {
                    ans=(ans+m[(1<<i)-d])%mod;
                }
            }
            m[d]++;
        }
        return ans;
    }
};