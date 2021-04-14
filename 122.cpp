/***** Third Visit *****/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy=INT_MAX,sell=0;
        for (int price:prices) {
            buy=min(buy,price-sell);
            sell=max(sell,price-buy);
        }
        return sell;
    }
};

/***** Second Visit *****/
/*
    Array:
    1. sort help?
    2. bucket sort further help?
    3. 2 ptr
    4. increasing index of stack
    5. 1 running ptr with sliding window (V)
    -----
    Each time we meet decreasing order, sell and buy another one.
    T:O(n) one pass / S:O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans=0, n=prices.size();
        if (n<=1) return ans;
        prices.push_back(-1); n++;
        int low=prices[0];
        for (int i=1; i<n; ++i) {
            if (prices[i]<prices[i-1]) {
                ans+=prices[i-1]-low;
                low=prices[i];
            }
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        /*
            buy in the localMin
            Sale in the localMax
            ----------------------
            Each time we meet a decreasing number, sale and buy one again
            T:O(n) with one pass, S:O(1)
        */
        int ans=0;
        int buy=prices[0];
        for (int i=1; i<prices.size(); ++i) {
            if (prices[i]<prices[i-1]) {
                ans+= prices[i-1]-buy;
                buy=prices[i];
            }
        }
        if (buy!=prices.back()) ans+=prices.back()-buy;
        return ans;
    }
};
