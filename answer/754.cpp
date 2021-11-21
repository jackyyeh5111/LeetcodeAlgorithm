/*
    greedy cannot find the optimistic sub structure.
    -----
    [1,2,3,4,5,6,7,8,9,10, ...]
    [1,1,-1,1,1,-1]
    0 |1 -1 | 3 -3 | 6 -6 | 10 2 -2 -10
    bfs -> TLE T:O(n^2)
    -----
    0 |1 -1 |3 -1 1 -3| 6 0 2 -4 4 -2 0 -6|10 ~ -10| 15 -15 |
    0  1     2          3                  4         5
*/
class Solution {
public:
    int reachNumber(int target)
    {
        long step=1, cur=0;
        while(!((cur+step>=abs(target))&&((cur+step)%2==abs(target)%2))) {
            cur+=step++;
        }
        return step;
    }
};
