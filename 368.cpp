class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp_idx(size, -1);
        vector<int> dp_cnt(size, 1);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j]) continue;
                if (dp_cnt[j] + 1 > dp_cnt[i]) {
                    dp_cnt[i] = dp_cnt[j] + 1;
                    dp_idx[i] = j;
                }
            }
        }

        // argmax
        int tb_idx = max_element(dp_cnt.begin(), dp_cnt.end()) - dp_cnt.begin();

        vector<int> ans;
        while(tb_idx != -1) {
            ans.push_back(nums[tb_idx]);
            tb_idx = dp_idx[tb_idx];
        }
        return ans;
    }
};

/* 
    1 2 4 8 
    k i   j

    idx: -1  0  0
    cnt:  1  1  1
    num:  1  2  3

    nums[i] % nums[k] == 0 => nums[j] % nums[k] == 0
 */