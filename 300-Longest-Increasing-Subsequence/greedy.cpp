class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis_arr;
        lis_arr.push_back(nums[0]);
        for (int num : nums) {
            if (num > lis_arr.back()) {
                lis_arr.push_back(num);
            }
            else { // binary search
                auto pos = lower_bound(lis_arr.begin(), lis_arr.end(), num);
                int idx = pos - lis_arr.begin();
                lis_arr[idx] = num;
            }
        }
        return lis_arr.size();
    }
};

/* 
    XXXXX Y
        i

    case 1:
        nums: [0 1 0 3 2] 3
        
        greedy: 0 1 2 3
        
        4 5 1 2 3

        4 5

 */