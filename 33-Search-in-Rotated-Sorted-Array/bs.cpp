/* 
    Wrong answer!

    Failed case:
        t = 8
        nums: 4,5,6,7,8,1,2,3
              l             r
                  m 

 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int left = 0, right = N - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target && target < nums[left])
                left = mid + 1;
            else if (nums[mid] > target && target >= nums[left])
                right = mid;
            else if (nums[mid] < target && target > nums[right])
                right = mid;
            else if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
        }
        return target == nums[left] ? left : -1;
    }
};

/* 
    t = 1
    2 3 4 0 1   ==> nums[m] > t && t < nums[l] ==> right
    l       r   
        m  

    0 1 2 3 4   ==> nums[m] > t && t >= nums[l] ==> left
    l       r
        m  

    3 4 0 1 2   ==> nums[m] < t && t <= nums[r] ==> right
    l       r
        m  

    0 1 ==> nums[m] < t && t <= nums[r] ==> right
    l r
    m
 */


