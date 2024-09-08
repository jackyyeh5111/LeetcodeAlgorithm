class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[(mid - 1) % nums.size()])
                break;

            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[mid];
    }
};

/* 
    Summary: Based on following cases, if right portion(nums[mid:right]) is increasing array, 
             minimum value can be found in left portion.

    1 2 3 4 5
        m
    l
            r
    
    5 1 2 3 4
      m  
      l
        r
    
    4 5 1 2 3
        m
    l
            r
    
    3 4 5 1 2
        m
    l
            r
    
    2 3 4 5 1
        m
    l
            r
 */