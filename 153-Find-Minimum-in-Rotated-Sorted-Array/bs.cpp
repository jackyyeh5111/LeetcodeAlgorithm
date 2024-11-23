class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        /* 
            3 4 5 1 2
                  m
                  l
                    r
         */
        while(left < right) {
            int mid = left + (right - left) / 2;
            int prev = mid == 0 ? size - 1 : mid - 1;
            if (nums[mid] < nums[prev])
                return nums[mid];
            // check if right portion is increasing
            else if (nums[mid] < nums[right]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left];

    }
};
/* 
    1 0
    l
      r
    m
 */
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