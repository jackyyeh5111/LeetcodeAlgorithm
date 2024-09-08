
/* 
    1 -2
    
    if nums[j] > 0:
        multiply by max history subarray(including previous element) product
    if nums[j] < 0:
        multiply by min history subarray(including previous element) product
    if nums[j] == 0:
        reset min, max history product to 0

        2 3 0 -2  4
    min 2 3 0 -2 -8
    max 2 6 0  0  4
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_product = 1; // -2
        int max_product = 1; // 6
        int ans = nums[0]; // 6
        for (int idx = 0; idx < nums.size(); idx++) {
            int num = nums[idx]; // 3
            int prev_min_product = min_product;
            min_product = min({num, num * min_product, num * max_product});
            max_product = max({num, num * prev_min_product, num * max_product});
            ans = max(ans, max_product);
        }
        return ans;
    }
};


/*
    wrong answer!

    先掃過一遍確認 negative number 的數量是否為偶數，若不是，取 
    max(preprods[0 : 最右負數 idx - 1], preprods[最左負數idx+1 : end])

    沒考慮到中間有 0 的 case!!!

    ----------------------------
    
      nums:   A B
    preprods: 1 A A*B

    P P N P P P N N P
        1         2
        
    [P P N] [P N 0]

    product from nums[i] to nums[j]:
        preprods[j] / preprods[i-1]
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> preprods;
        int N = nums.size();
        if (N == 1) return nums[0];

        preprods.resize(N + 1, 1);
        int neg_left = -1, neg_right = -1;
        for (int i = 1; i <= N; ++i) {
            preprods[i] = preprods[i-1] * nums[i-1];
            if (nums[i-1] < 0) {
                if (neg_left == -1) // the first one
                    neg_left = i;
                neg_right = i;
            }
        }

        if (preprods[N] >= 0)
            return preprods[N];
        
        return max(preprods[N] / preprods[neg_left], preprods[neg_right-1] / preprods[0]);
    }
};
