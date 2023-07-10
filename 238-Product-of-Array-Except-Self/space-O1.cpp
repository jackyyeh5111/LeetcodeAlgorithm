/* 
    left, right dp array 只跟前一時刻數值有關(Basic I (时间序列型))，所以可以 condensed to a variable to represent

        nums:  1  2  3  4
        left:  1  1  2  6
       right: 24 12  4  1
 */
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        int left = 1, right = 1;
        vector<int> ans(N, 1);
        for (int i=0; i < N; i++) {
            ans[i] *= left;
            ans[N - 1 - i] *= right;
            left *= nums[i];
            right *= nums[N - 1 - i];
        }
        return ans;
    }
};

/* 
    Approach2: Optimized space O(1)

    prefix 用 array，但 suffix 只要用一個變數就可以表示，真厲害的想法！
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);

        /* 
            nums:  1 2 3 4
            ans:   1 1 2 6

         */
        for (int i = 1; i < N; ++i) {
            ans[i] = nums[i-1] * ans[i-1];
        }
        int suffix = 1;
        for (int i = N-1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};