/***** Second Visit *****/
/*
    dp solution
    T:O(amount * # of coins)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for (int i=1; i<=amount; ++i) {
            for (int coin:coins) {
                if (i<coin) continue;
                else if (dp[i-coin]==INT_MAX) continue;
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};

/***** First Visit *****/
/*
    typical dp Problem
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,INT_MAX); dp[0]=0;
        for (int i=1; i<=amount; ++i) {
            for (int c:coins) {
                if (i>=c&&dp[i-c]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        return dp.back()==INT_MAX?-1:dp.back();
    }
};
