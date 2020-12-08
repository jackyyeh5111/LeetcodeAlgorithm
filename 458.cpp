/*
    4 bucketes, 15 mins, 15 mins
       x x x x
    1.   ---
    2. ---
    only needs 2 pigs to find the poisoned one. -> log(4) if 1 test
    =====
    8 bucketes, 15 mins, 15 mins (3 pigs 1 test)
       x x x x x x x x
    1. -------
    2. ---     ---
    3. -   -   -   -
    only needs 3 pigs to find the poisoned one. -> log(8) if 1 test
    -----
    1. What if you only have one shot?
      If we have x pigs, we could use them to represent (encode) 2^x buckets.
    2. What if we could have more than one attempts?
      What does the binary form mean? It's much easier if we regard it as:
 
      0 means the pig does not drink and die.
      1 means the pig drinks in the first (and only) round.
      We could generalise with:
 
      0 means the pig does not drink and die.
      1 means the pig drinks in the first round and die.
      2 means the pig drinks in the second round and die.
 
      If we have t attempts, we could use t+1-based number to represent (encode) the buckets. (That's also why the first conclusion uses the 2-based number)
     ...
     t means the pig drinks in the t-th round and die.
    refers: https://leetcode.com/problems/poor-pigs/discuss/94273/Solution-with-detailed-explanation
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times=minutesToTest/minutesToDie;
        if (times==0) return -1;
        return ceil(log(buckets)/log(times+1));
    }
};
