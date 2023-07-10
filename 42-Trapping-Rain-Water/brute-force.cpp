class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int ans = 0;
        for (int i=1; i < N - 1; i++) {
            int left_max = height[i], right_max = height[i];
            for (int j = i-1; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }
            for (int j = i+1; j < N; j++) {
                right_max = max(right_max, height[j]);
            }
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
    }
};