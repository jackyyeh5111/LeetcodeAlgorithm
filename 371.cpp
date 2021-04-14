/*
    0110
    0011 +)
    1001

    0110
    1001 +) -> 0110+1=0111
    T:O(32)/S:O(1)

    ref: https://ryanstutorials.net/binary-tutorial/binary-negative-numbers.php
*/
class Solution {
public:
    int getSum(int a, int b) {
        int c=0,ans=0;
        for (int i=0; i<32; ++i) {
            int abit=a&1, bbit=b&1;
            if (abit^bbit^c) ans=ans|(1<<i);
            c=(abit&&bbit)||(abit&&c)||(bbit&&c);
            a>>=1; b>>=1;
        }
        return ans;
    }
};
