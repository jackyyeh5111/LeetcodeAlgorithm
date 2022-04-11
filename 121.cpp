#include "utils.hpp"

/* 
ref:
https://hackmd.io/vIowB4X6RZ-POXsQOqag7g
 */

/* Soluiton1 is more elegant */
class Solution2 {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 1) return 0;
    int cost = prices[0], max_profit = INT_MIN;
    for (int i = 1; i < n; i++) {
      max_profit = max(max_profit, prices[i] - cost);
      cost = min(cost, prices[i]);
    }

    return max_profit < 0 ? 0 : max_profit;
  }
};

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_val = INT_MAX;
    int ans = 0;
    for (int i = 0; i < prices.size(); i++) {
      min_val = min(prices[i], min_val);
      ans = max(ans, prices[i] - min_val);
    }

    return ans;
  }
};