class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool is_one_occur = false;
        int size = nums.size();
        // iter 1: convert num <= 0 to value "1"
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) is_one_occur = true;
            else if (nums[i] <= 0 || nums[i] > size) {
             nums[i] = 1;
            }
            
        }
        
        if (!is_one_occur) return 1;

        /* 
            -1 -2 2 1 1
         */
        // iter 2: negate corrsponding position
        for (int i = 0; i < size; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) // avoid duplicate operation
                nums[idx] = -nums[idx];
        }

        // iter 3: check first position whose value is not negative (except for first position)
        int pos;
        for (pos = 1; pos < size; pos++) {
            if (nums[pos] > 0) break;
        }
        return pos + 1;
    }
};

/* 
    bool is_one_occur = false

    case1: 
        nums: 2 3 1 
        
        iter1: 2 3 1
        iter2: 2 -3 -1  
    
    case2: 
        bool is_one_occur = true
        nums: 5 3 1 
        
        iter1: 1 3 1
        iter2: 1 3 -1
    
    
 */