/*
    Naive binary search problem
    The input element is guatenteed in ascending order
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l=0,r=nums.size();
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) r=mid;
            else l=mid+1; // l is the last tone satisfies criteria.
        }
        return -1;
    }
};
