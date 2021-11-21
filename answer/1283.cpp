/*
    binary search from 0 - max possible dividor k.
    T:O(nlogk) / S:O(1)
*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int l=0,r=*max_element(nums.begin(),nums.end());
        while (l<r) {
            int mid=(l+r)/2;
            if (feasible(nums,threshold,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }

    bool feasible(vector<int>& nums, int threshold, int d)
    {
        if (d<=0) return false;
        int sum=0;
        for (int num:nums) sum+=(num+(d-1))/d;
        return sum<=threshold;
    }
};
