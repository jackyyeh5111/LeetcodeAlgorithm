/*
    DP
    for position i: !(dp[i-1]&dp[i-2]&dp[i-3])
    1 2 3 4 5 6 7 8 9 10 11 12
    T T T F T T T F ...
    T:O(n)/S:O(n)
    -------
    after observing the example, we know each 4*k will loose game, others will win.
    T:O(1)/S:O(1)
*/
class Solution {
public:
    bool canWinNim(int n) {
        return !(n%4==0);
    }
};
