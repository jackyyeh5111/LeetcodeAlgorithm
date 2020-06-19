class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        /*
        brute force, traverse all element and find target, T:O(n)
        sorted order->binary search->T:O(logN)

        0 1 2 3 4 5  pivot is in the begining, i.e. no rotated
        ^         ^
        2 3 4 5 0 1  pivot is in right part
        ^   ^
        5 0 1 2 3 4  pivot is in left part
        ^   ^
        */
        if (nums.size()==0) return false;
        int l=0,r=nums.size()-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if (nums[mid]==target) return true;
            // cannot tell where the pivot is
            if ((nums[l]==nums[mid])&&(nums[mid]==nums[r])) {l++,r--;}
            // find out where pivot is
            else if (nums[l]<nums[r]) {
                if (nums[mid]>target) r=mid-1;
                else l=mid+1;
            }
            // we dont need to worry that pivot is in left because it will fall into the case we cannot tell where the pivot is
            else if (nums[mid]>=nums[l]){
                if (nums[mid]>target&&nums[l]<=target) r=mid-1;
                else l=mid+1;
            }
            else {
                if (nums[mid]<target&&nums[r]>=target) l=mid+1;
                else r=mid-1;
            }
        }
        return false;

    }
};
