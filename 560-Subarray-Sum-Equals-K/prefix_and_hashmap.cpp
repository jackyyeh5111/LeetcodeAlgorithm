class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        unordered_map<int, int> presum_cnt;
        presum_cnt[0] = 1;
        int cur_sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            ans += presum_cnt[cur_sum - target];
            presum_cnt[cur_sum]++;
        }
        return ans;
    }
};

/* 
    0 2 -1, k = 1
    i
         j

          nums:   1 4 3 2
    prefix_sum: 0 1 5 8 10

    
    每個起始位置 j，都看了所有前面 i，此舉動重複，可以用 hashmap 把前面 prefix sum 出現次數加總即可
    i = 0, 1    when j = 2
    i = 0, 1, 2 when j = 3

    prefix_sum[i] - prefix_sum[j] = target
    => (convert into)
    prefix_sum[j] = prefix_sum[i] - target

    1. two for loop + prefix_sum => time: O(n^2), space: O(n)
    2. prefix_sum + hashmap => time: O(n), space: O(n)
             

 */