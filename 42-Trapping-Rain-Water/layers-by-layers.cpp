/* 
    Time limit exceed
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int max_val = *max_element(height.begin(), height.end());
        int ans = 0;
        for (int i = 1; i <= max_val; i++) {
            int start = -1, end = -1, count = 0;
            for (int j = 0; j < height.size(); j++) {
                if (height[j] >= i) {
                    if (start == -1)
                        start = j;
                    end = j;
                    count++;
                }
            } 
            ans += (end - start + 1) - count;
        }
        return ans;
    }
};
