/*
    10101
    10100
    10011
    10000
   >11111
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int bitwiseComplement(int N)
    {
        if(N==0) return 1;
        int mask=N;
        while(mask&(mask-1)) mask&=(mask-1);
        mask|=(mask-1);
        return mask&(~N);
    }
};
