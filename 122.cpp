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
