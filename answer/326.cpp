/*
    multiplyer of 3 -> # of odd bits  == # of even bits
    -----
    1 2+1 8+1 26+1
    0000001
    0000011
    0001001
    0011011
    1010001
*/

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n==0) return 0;
        double t=log10(n)/log10(3);
        return t==floor(t);
    }
};
