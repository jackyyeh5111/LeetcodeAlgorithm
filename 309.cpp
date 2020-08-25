class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        /*
            refers to: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
            s0 Stay at s0, or rest from s2 (can buy)
            s1 Stay at s1, or buy from s0 (can sell)
            s2 Only one way from s1 (need to rest)
        */
        int size=prices.size();
        if (size<2) return 0;
        vector<int> s0(size,0); s0[0]=0;
        vector<int> s1(size,0); s1[0]=-prices[0];
        vector<int> s2(size,0); s2[0]=INT_MIN;
        for (int i=1; i<size; ++i) {
            s0[i]=max(s0[i-1],s2[i-1]);
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s2[i]=s1[i-1]+prices[i];
        }
        return max(s0[size-1],s2[size-1]);
    }
};
