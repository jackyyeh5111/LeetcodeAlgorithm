/*      
    dp[i]: subarray with the largest product that ends at nums[i]

    X [X X i] X X 
    dpmax[i] = max(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i], nums[i])
    dpmin[i] = min(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i], nums[i])

        [1, -2, 3,  0, 5 -2]
    max: 1  -2. 3   0. 5  0   
    min: 1  -2  -6  0  0 -10     
*/
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        vector<int> dpmax(N, INT_MIN), dpmin(N, INT_MAX);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        
        int ans = nums[0];
        for (int i = 1; i < N; ++i) {
            dpmax[i] = max(max(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]), nums[i]);
            dpmin[i] = min(min(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]), nums[i]);
            ans = max(ans, dpmax[i]);
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
