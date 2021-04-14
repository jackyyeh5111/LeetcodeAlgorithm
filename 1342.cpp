/*
    1110 14
    0111 7
    0110 6
    0011 3
    0010 2
    0001 1
    0000 0
*/
class Solution {
public:
    int numberOfSteps (int num)
    {
        int ans=0;
        while (num) {
            ans+=(num&1);
            if (num>>1) ans++;
            num>>=1;
        }
        return ans;
    }
};
