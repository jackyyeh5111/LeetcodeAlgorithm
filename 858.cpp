/*    
    draw some stacked reflection square. E.g. 0123 represent 4 corner point.

    2121212121212121
    3030303030303030
    2121212121212121
    3030303030303030

    refers: https://leetcode.com/problems/mirror-reflection/discuss/938821/Python-pure-geometry-illustrated
*/
class Solution {
public:
    int mirrorReflection(int p, int q)
    {
        int k=1;
        while ((k*q)%p) k++;
        return k%2==0?2:(k*q/p)%2;

    }
};
