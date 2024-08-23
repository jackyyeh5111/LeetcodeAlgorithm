class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, 0));
        
        for (int i = 1; i <= N1; i++) {
            for (int j = 1; j <= N2; j++){
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;  
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[N1][N2];
    }
};

/* 
    dp[i][j]: the maximum number of connecting lines we can draw in this way for nums[1:i], nums[1:j].

    XXXX Y
    XXX Z

    max(dp[i-1][j], dp[i][j-1], dp[i][j] + 1)

      # a p p
    # 0 0 0 0
    a 0 1 1 1
    d 0 1 1 1
    p 0 1 2 2
 */