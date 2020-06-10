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
