/* 
    [0, 1], target = 1
     m
     l 
        r

    Find which left or right portion is sorted, then check if target belong to that portion.

    case 1:
        [4,5,6,7,0,1,2], target = 0
               m
         l
                     r
    case 2:
        [6,7,0,1,2,4,5], target = 0
               m
         l
                     r
    
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // left portion is sorted
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            // right portion is sorted
            else {
                if (target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }
};


/* Wrong answer!

    Fail case:
        nums: [3, 1]
        target: 1
 */
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
                return mid;

            bool left_cont = nums[mid] > nums[left]; // left continuous
            if (left_cont) {
                if (target < nums[mid] && target >= nums[left])
                    right = mid;
                else 
                    left = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else 
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};

/* 
    Wrong answer!

    Failed case:
        t = 0
        nums: 1 0
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
            bool left_cont = nums[left] < nums[mid] ? true : false;
            if (left_cont) {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            else {
                if (target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return target == nums[left] ? left : -1;
    }
};

/* 
    左右一定有一邊的區間是連續的

    t = 5
    6,7,8,1,2,3,4,5
    l             r
          m 
    
    t = 0
    1 0
    l r
    m

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


