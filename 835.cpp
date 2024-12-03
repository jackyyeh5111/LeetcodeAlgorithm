class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        // assign pad img
        int pad_dim = n + 2 * (n - 1);
        vector<vector<int>> pad_img = vector<vector<int>>(pad_dim, vector<int>(pad_dim));
        for (int r = 0; r < n; r++) 
            for (int c = 0; c < n; c++)
                pad_img[r+n-1][c+n-1] = img2[r][c];
        
        // convolution
        int ans = 0;
        for (int r = 0; r < pad_dim - n + 1; r++) {
            for (int c = 0; c < pad_dim - n + 1; c++){
                int num_match = 0;
                for (int kr = 0; kr < n; kr++) {
                    for (int kc = 0; kc < n; kc++) {
                        if (img1[kr][kc] && pad_img[r + kr][c + kc])
                            num_match++;
                    }
                }
                ans = max(ans, num_match);
            }
        }
        return ans;
    }
};

