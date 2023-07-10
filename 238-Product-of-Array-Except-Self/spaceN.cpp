class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> left(N, 1), right(N, 1);
        vector<int> ans(N);
        for (int i = 1; i < N; ++i) {
            left[i] = left[i-1] * nums[i-1];
            right[N - 1 - i] = right[N - i] * nums[N - i];
        }
        for (int i = 0; i < N; ++i) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};

/* 
    ans[i] = left[:i] * right[i+1:]
 
    left:   1  L1 L2 L3
    right:  R3 R2 R1 1
 */