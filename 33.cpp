/***** Third Visit *****/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>=nums[l]) {
                if (target<nums[l]||target>nums[mid]) l=mid+1;
                else r=mid-1;
            }
            else { // nums[mid]<nums[l]
                if (target<nums[mid]||target>=nums[l]) r=mid-1;
                else l=mid+1;
            }
        }
        return -1;
    }
};

/***** Second Visit *****/
/*
    3,4,5,6,7,1,2
    sorted nums[l]<nums[r]
    else rotated
    nums[mid]>nums[l] pivot lies in mid~r, left part is sorted!
    else pivot lies in l~mid, right part is sorted!
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n=nums.size();
        int l=0,r=n;
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]==target) return mid;
            else if (nums[l]<nums[r-1]) {
                if (nums[mid]<target) l=mid+1;
                else r=mid;
            }
            else if (nums[mid]>nums[l]) {
                if (target<nums[mid]&&target>=nums[l]) r=mid;
                else l=mid+1;
            }
            else {
                if (target>nums[mid]&&target<=nums[r-1]) l=mid+1;
                else r=mid;
            }
        }
        return -1;
    }
};

/***** First Visit *****/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // T:O(logn)
        int start = 0; int end = nums.size()-1;
        while(start < end ) {
            int mid = (start+end)/2;
            if (nums[mid]==target) return mid;
            else {
                if (nums[start]<nums[end]){
                    //all consecutive
                    if(target>nums[mid]) start=mid+1;
                    if(target<nums[mid]) end=mid-1;
                }
                else if (nums[mid]>nums[start]) {
                    // left consecutive
                    if(target>=nums[start]&&target<=nums[mid-1]) end = mid-1;
                    else start = mid+1;
                }
                else if (nums[mid]<=nums[start]) {
                    // right consecutive
                    if(target>=nums[mid+1]&&target<=nums[end]) start = mid+1;
                    else end = mid-1;
                }
            }
        }
        if (start==end&&start<nums.size()&&nums[start]==target) return start;
        else return -1;
    }
};
