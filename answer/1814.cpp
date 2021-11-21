/*
    0 <= i < j < nums.length
    nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

    brute force:
    T:O(n^2)/S:O(1)
    -----
    [42,11,1,97]
    1 11 42 97 111
    1 11 24 79 111
    0 0  18 18 0

*/
class Solution {
public:
    int countNicePairs(vector<int>& nums)
    {
        int mod=1e9+7;
        unordered_map<int,int> mp;

        for (int num:nums) {
            int inv=0, t=num;
            while (t) {
                inv=inv*10+t%10;
                t/=10;
            }
            int diff=num-inv;
            mp[diff]++;
        }
        int ans=0;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            if (it->second<2) continue;
            long t=it->second;
            ans=(ans+(t*(t-1)/2)%mod)%mod;
        }
        return ans;
    }
};
