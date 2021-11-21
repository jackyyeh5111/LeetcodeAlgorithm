/***** Second Visit *****/
/*
    sorted array
    1. 2 ptr
    2. binary search (v)
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n=nums.size();
        int l=0,r=n;
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
};

/***** First Visit *****/
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
