class Solution {
public:
    // T:O(logn)
    int searchInsert(vector<int>& nums, int target)
    {
        int l=0, r=nums.size()-1;
        while (l<=r) {
            int mid = (l+r)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return max(l,r); // JUST need to return l.
    }
};
