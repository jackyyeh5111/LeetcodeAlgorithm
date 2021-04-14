/*
    similar to problem 122, advanced thought in problem 123.
    buy=priceA-sell+fee
        -> cost to minimize, the actual cost would be price - the profiit we've made.
    sell=priceB-buy=priceB-priceA+sell-fee
        -> profit to maximize, max profit would be price - the min cost we've made.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int buy=INT_MAX,sell=0;
        for (int price:prices) {
            buy=min(buy,price-sell+fee);
            sell=max(sell,price-buy);
        }
        return sell;
    }
};
