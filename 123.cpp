#include "utils.hpp"

/*
leetcode (my post):
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/3103753/c-easy-understanding-dp-approach/?orderBy=hot


注意等号右边的变量都是前一天的状态. 另外需要考虑初始状态:
buy1=-inf, sold1=0, buy2=-inf, sold2=0

狀態轉移方程：
    hold1[k] = max(hold1[k-1], -p)
    sold1[k] = max(sold1[k-1], hold1[k-1] + p)
    hold2[k] = max(hold2[k-1], sold1[k-1] - p)
    sold2[k] = max(sold2[k-1], hold2[k-1] + p)
    
    由上所知，第 k 天狀態根據第 k-1 天來決定，所以我們可以簡化 dp array，改用 variable 
    來儲存 k-1 狀態即可 ==========> 

    hold1 = max(hold1, -p)
    sold1 = max(sold1, hold1+p)
    hold2 = max(hold2, sold1-p)
    sold2 = max(sold2, hold2+p)

    ex:
        Input: prices = [3,3,5,0,0,3,1,4]
        Output: 6

        hold1: -3 -3 -3 0 0 0 0 0
        sold1: 0   0  2 2 2 3 3 4
        hold2: -3 -3 -3 2 2 2 2 2
        sold2: 0   0  0 2 2 5 5 6
 */

/* compressed space memory  */
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        // definition
        // index trick
        // status initialization
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;
        
        // transfer function
        for (int i = 1; i < prices.size(); ++i) {
            // reverse updating
            sell2 = max(sell2, buy2 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
        }

        // answer
        return max(sell1, sell2);
    }
};

/* dynamic programming  */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // status initialization
        int n = prices.size();
        vector<int> buy1(n), sell1(n), buy2(n), sell2(n);
        buy1[0] = -prices[0];
        sell1[0] = 0;
        buy2[0] = INT_MIN;
        sell2[0] = 0;
        
        // transfer function
        for (int i = 1; i < n; ++i) {
            // reverse updating (omit temp variables)
            sell2[i] = max(sell2[i-1], buy2[i-1] + prices[i]);
            buy2[i] = max(buy2[i-1], sell1[i-1] - prices[i]);
            sell1[i] = max(sell1[i-1], buy1[i-1] + prices[i]);
            buy1[i] = max(buy1[i-1], -prices[i]);
        }

        // answer
        return max(sell1[n-1], sell2[n-1]);
    }
};