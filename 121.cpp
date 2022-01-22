#include "utils.hpp"

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