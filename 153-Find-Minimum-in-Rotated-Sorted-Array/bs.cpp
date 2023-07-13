/* 
    3 cases:

    1 2 3 4 5 <-
    S   M   B

    3 4 5 1 2 ->
    S   M   S
    
    5 1 2 3 4 <-
    B   M   B   

    2 1
    l r
    m   
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int left = 0, right = N - 1;
        int mid;
        while (true) {
            mid = left + (right - left) / 2;
            int prev_idx = mid - 1 == -1 ? N - 1 : mid - 1;
            if (nums[prev_idx] >= nums[mid])
                break;

            if (nums[N-1] < nums[mid])
                left = mid + 1;
            else 
                right = mid;
        }
        return nums[mid];
    }
};

/* 
    [4,5,6,7,0,1,2]
             ^
    Find element(int this case is "0") that split array into two increment subarrays. 
    
    [0 1]
     l r
       m      
    
    [1 0]
     l r
       m       
 */
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            // More simple way to compare
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};

/* 
    3 4 5 6 1 2
          l r
          m  

    6 1 2 3 4 5
    l r       
    m    

    1 2 3
    l r 
    m  


    Find min in nums[m:r] if nums[m] > nums[l] && ,nums[m] > nums[r] 
    otherwise nums[l:m] 
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int left = 0, right = N - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};





