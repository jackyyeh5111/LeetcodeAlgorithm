class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int cand : candidates) {
            for (int i = cand; i <= target; ++i) {
                for (auto comb : dp[i-cand]) {
                    dp[i].push_back(comb);
                    dp[i].back().push_back(cand);
                }
            }
        }
        return dp[target];
    }
};

