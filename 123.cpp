/*
    Refer to https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution

    dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]

    For k transactions, on i-th day,
    if we don't trade then the profit is same as previous day dp[k, i-1];
    and if we bought the share on j-th day where j=[0..i-1], then sell the
    share on i-th day then the profit is prices[i] - prices[j] + dp[k-1, j-1] .
    Actually j can be i as well. When j is i, the one more extra item prices[i]
    - prices[j] + dp[k-1, j] = dp[k-1, i] looks like we just lose one chance of
    transaction.
*/
class Solution {
public:
    /*
    Here, the oneBuy keeps track of the lowest price, and oneBuyOneSell keeps
    track of the biggest profit we could get.
    Then the tricky part comes, how to handle the twoBuy? Suppose in real life,
    you have bought and sold a stock and made $100 dollar profit. When you want
    to purchase a stock which costs you $300 dollars, how would you think this?
    You must think, um, I have made $100 profit, so I think this $300 dollar
    stock is worth $200 FOR ME since I have hold $100 for free.
    There we go, you got the idea how we calculate twoBuy!! We just minimize
    the cost again!! The twoBuyTwoSell is just making as much profit as
    possible.
    Hope this explanation helps other people to understand this!
    */
    int maxProfit(vector<int>& prices)
    {
        int oneBuy=INT_MAX;
        int oneBuyOneSale=0;
        int twoBuy=INT_MAX;
        int twoBuyTwoSale=0;

        for (int price:prices) {
            oneBuy=min(oneBuy,price);
            oneBuyOneSale=max(oneBuyOneSale, price-oneBuy);
            twoBuy=min(twoBuy,price-oneBuyOneSale);
            twoBuyTwoSale=max(twoBuyTwoSale,price-twoBuy);
        }
        return twoBuyTwoSale;
    }
};
