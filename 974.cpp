class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 1) create presum
        int size = nums.size();

        // 2) for loop with remainder map
        unordered_map<int, int> remainders;
        remainders[0] = 1;
        int ans = 0;
        int acc_sum = 0;
        for (int num : nums) {
            acc_sum += num;
            int remainder = abs(acc_sum) % k;
            if (acc_sum < 0 && remainder > 0)
                remainder = k - remainder;
            ans += remainders[remainder];
            remainders[remainder]++;
        }
        return ans;
    }
};

/* 
    [4 5 0 -2 -3 1]
       i
       j
    j = 0, i = 0
    j = 1, i = 0, 1
    j = 2, i = 0, 1, 2
    
    presum[i:j] = presum[j] - presum[i-1]
                                  ^
                            we only want to know "count" of this, can use hashmap

    presum[i:j] is divisible by k <= remainder of presum[j] == remainder of presum[i-1]

    edge case:
        How about presum < 0?
        -1 => k - 1
        -2 => k - 2

 */