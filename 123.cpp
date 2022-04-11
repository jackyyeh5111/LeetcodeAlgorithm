#include "utils.hpp"

/*
注意等号右边的变量都是前一天的状态. 另外需要考虑初始状态:buy1=-inf, sold1=0,
buy2=-inf, sold2=0

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

class Solution {
 public:
  int maxProfit(vector<int>& prices) {}
};
