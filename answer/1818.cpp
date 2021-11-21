/*
    online sorting + dp
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
    {
        int mod=1e9+7;
        set<int> s(nums1.begin(),nums1.end());
        int n=nums1.size();
        long csum=0;
        for (int i=0; i<n; ++i) csum+=abs(nums1[i]-nums2[i]);
        long ans=csum;
        for (int i=0; i<n; ++i) {
            long k=csum-abs(nums1[i]-nums2[i]);
            auto lit=s.lower_bound(nums2[i]);
            if (lit!=s.end()) ans=min(ans,k+abs(*lit-nums2[i]));
            if (lit!=s.begin()) ans=min(ans,k+abs(*prev(lit)-nums2[i]));
        }
        return ans%mod;
    }
};
