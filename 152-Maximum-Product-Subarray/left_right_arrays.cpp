/* 
            XXX 0 XXX 0 XXX
    left ->     
                            <- right
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        int ans = INT_MIN;
        int left = 1, right = 1;
        for(int i = 0; i < N; i++) {
            left *= nums[i];
            right *= nums[N - 1 - i];
            ans = max(ans, left);
            ans = max(ans, right);

            // handle edge case: value 0
            if (left == 0) left = 1;
            if (right == 0) right = 1;
        }
        return ans;
    }
};