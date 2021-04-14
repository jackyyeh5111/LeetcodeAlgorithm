/*
    memoise recursion?
    -----
    if x > y return x-y
    else if x==y return 0
    else min(brokenCalc(X*2,Y),brokenCalc(X-1,y))
    -----
    greedy transform Y to X

    The motivation for this is that it turns out we always greedily divide by 2:

    If say Y is even, then if we perform 2 additions and one division, we could instead perform one division and one addition for less operations [(Y+2) / 2 vs Y/2 + 1].

    If say Y is odd, then if we perform 3 additions and one division, we could instead perform 1 addition, 1 division, and 1 addition for less operations [(Y+3) / 2 vs (Y+1) / 2 + 1].

    T:O(logY)/S:O(1)
*/
class Solution {
public:
    int brokenCalc(int X, int Y)
    {
        long x=X,y=Y;
        if (x>=y) return x-y;
        int ans=0;
        while((y+1)/2>x) {ans+=(1+y%2); y=(y+1)/2;}
        return min(x*2-y+1,x-(y+1)/2+1+y%2)+ans;
    }
};
