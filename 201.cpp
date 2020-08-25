class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        /*
            0101 5
            0110 6
            0111 7

            010000111
            010001000
            010001001
            010001010
        */
        if (m==n) return m;
        int diffs=n-m;
        int bits=0;
        while(diffs){ bits++; diffs/=2; }
        return ((m&n)>>bits)<<bits;

    }
};
