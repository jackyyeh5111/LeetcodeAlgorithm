/*
This is a classic knapsack problem.

dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
State transition:

not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
using the ith coin, since we can use unlimited same coin, we need to know how many ways to make up amount j - coins[i-1] by using first i coins(including ith), which is dp[i][j-coins[i-1]]
Initialization: dp[i][0] = 1
*/

class Solution {
public:
    // T:O(nM), S:O(nm)
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> table(coins.size()+1, vector<int>(amount+1));
        table[0][0]=1;
        for (int i=1; i<=coins.size(); ++i) {
            table[i][0]=1;
            for (int j=0; j<=amount; ++j) {
                if (j>=coins[i-1])
                    table[i][j]=table[i-1][j]+table[i][j-coins[i-1]];
                else
                    table[i][j]=table[i-1][j]+0;
            }
        }
        return table[coins.size()][amount];
    }

};

class Solution {
public:
    int counts = 0;
    // T:O(n^n)
    int change(int amount, vector<int>& coins) {
        if (coins.size()==0 && amount==0) return 1;
        check(amount, coins, 0);
        return counts;
    }

    void check(int amount, vector<int>& coins, int cur)
    {
        if (amount<0 || cur>=coins.size()) return;
        if (amount==0) {
            counts++;
            return;
        }
        for (int i=cur; i<coins.size(); ++i)
            check(amount-coins[i], coins, i);
    }
};
