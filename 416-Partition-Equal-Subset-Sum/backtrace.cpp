class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;
        return dfs(nums, 0, 0, target);
    }
    bool dfs(const vector<int>& nums, int idx, int acc_sum, int target) {
        acc_sum += nums[idx];
        if (acc_sum == target) return true;
        
        for (int i = idx+1; i < nums.size(); i++) {
            if (dfs(nums, i, acc_sum, target))
                return true;
        }
        return false;
    }
};

/* 

                       []  
                /              \
             [1] (pick 1)        []  (not pick 1)
           /     \             /     \
        [1,2]       [1]       [2]       []    

    convert problem to 494. traget sum
        nums = [1, 5, 11, 5], target = 11 = sum(nums) / 2
    
    arr: 1 2 3 4
    
           0 1 2 3 4 5
    {1}    T T F F F F
    {1 2}  T T T T F F    
    {1 2 3}

    sum: 10
    target: 5

    nums: [1,2,3,4]
                       []  
                /              \
             [1] (pick 1)        []  (not pick 1)
           /     \             /     \
        [1,2]       [1]       [2]       []    

 */