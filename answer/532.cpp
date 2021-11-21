/*
    use a hash set with each num.
    For each num, treat it as the small one and find if big one exists.
    -10^7 <= nums[i] <= 10^7  <--- Notice int overflow
    0 <= k <= 107 <--- k is non-negative num.
    T: 2 pass O(n)/S:O(n)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<long,int> m;
        for (int num:nums) m[num]++;
        int ans=0;
        for (auto p:m) {
            if (k==0) ans+=p.second>=2;
            else if (m.count(p.first+(long)k)>0) ans++;
        }
        return ans;
    }
};
