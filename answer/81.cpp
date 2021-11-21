/***** Third Visit *****/
// T:O(n)/S:O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int l=0, r=nums.size()-1;
        while (l<=r) {
            int mid=(l+r)/2;
            if (nums[mid]==target) return true;
            else {
                if (nums[l]<nums[r]) {
                    if (nums[mid]>target) r=mid-1;
                    else l=mid+1;
                }
                else if (nums[l]>nums[r]) {
                    if (nums[mid]>=nums[l]) { // pivot in the right part
                        if (nums[mid]<target||target<nums[l]) l=mid+1;
                        else r=mid-1;
                    }
                    else { // pivot in the left part
                        if (nums[mid]>target||target>nums[r]) r=mid-1;
                        else l=mid+1;
                    }
                }
                else if (nums[l]==target) return true;
                else {l++; r--;}
            }
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    linear searching:  T:O(n)/S:O(1)
    binary search: T:O(logn)/S:O(1)

    Non-duplicated nums
    1234567
    3456712
    7123456
    -----
    duplicated nums
    1123445
    1234451
    3445112

    think about below example
    2500012
    we are not sure where the pivot is, then we should check both sides.
    T(n)=2T(n/2)+O(1)=T:O(n)/S:O(1)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            if (nums[l]==nums[r]) {
                while(l<=r) {
                    if (nums[l++]==target) return true;
                }
                return false;
            }
            int mid=(l+r)/2;
            if (nums[mid]==target) return true;
            if (nums[l]<nums[r]) {
                if (nums[mid]>target) r=mid-1;
                else l=mid+1;
            }
            else {
                if (nums[mid]>=nums[l]) {
                    if (target<nums[mid]&&target>=nums[l]) r=mid-1;
                    else l=mid+1;
                }
                else {
                    if (target>nums[mid]&&target<=nums[r]) l=mid+1;
                    else r=mid-1;
                }
            }
        }
        return false;
    }
};

/***** First Visit *****/
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
