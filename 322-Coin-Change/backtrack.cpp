/* 
    Easier backtrack
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        backtrack(coins, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
    void backtrack(const vector<int>& coins, int amount, int count, int& ans) {
        if (amount == 0) {
            // answer only gets updated when amount == 0
            ans = min(ans, count);
            return;
        }
        else if (amount < 0) return;
        
        for (int coin : coins) {
            backtrack(coins, amount - coin, count + 1, ans);
        }
    }
};

/* 

 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int count = backtrack(coins, amount, 0);
        return count == INT_MAX ? -1 : count;
    }
    int backtrack(const vector<int>& coins, int amount, int count) {
        if (amount == 0)
            return count;
        else if (amount < 0) 
            return INT_MAX;
        
        int min_cnt = INT_MAX;
        for (int coin : coins) {
            int temp = backtrack(coins, amount - coin, count + 1);
            min_cnt = min(min_cnt, temp);
        }
        return min_cnt;
    }
};
