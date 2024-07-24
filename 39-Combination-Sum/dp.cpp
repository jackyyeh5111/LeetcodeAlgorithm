class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0].push_back({});

        for (int cand : candidates) {
            for (int i = cand; i <= target; i++) {
                for (vector<int> comb : dp[i - cand]) {
                    comb.push_back(cand);
                    dp[i].push_back(comb);
                }
            }
        }
        return dp[target];
    }
};

/* 
    dp[i]: the number of possible combinations that sum up to i in the previous itertaion.

          0 1  2   3    4    5              6  7
      {2} 0 0 {2}  0 {2,2}   0         {2,2,2} 0         
    {2,3} 0 0 {2} {3}{2,2}{2,3} {{2,2,2},{3,3}}
  {2,3,6} ... 
{2,3,6,7}

    target * 1 +  target * 2 + ... + target * N
    - Time: O(target * N2)
    - Space: O(target * N2)
 */