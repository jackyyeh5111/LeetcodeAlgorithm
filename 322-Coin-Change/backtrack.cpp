class Solution {
public:
    int ans;
    int coinChange(vector<int>& coins, int amount) {
        ans = amount + 1;
        backtrack(coins, amount, 0, 0);
        return ans == amount + 1 ? -1 : ans;
    }
    void backtrack(const vector<int>& coins, int amount, int sum, int coin_cnt) {
        if (sum == amount) {
            ans = min(ans, coin_cnt);
            return;
        }
        else if (sum > amount) return;

        for (int coin : coins) {
            backtrack(coins, amount, sum + coin, coin_cnt + 1);
        }
    }
};
