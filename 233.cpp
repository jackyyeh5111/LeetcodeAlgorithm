class Solution {
public:
    int countDigitOne(int n)
    {
        /*
            23 1+1*11+(2-1)
               ^   ^

            344 x1x 30+(4+1)

            consider each digit, spit into left/right part in decimal.
        */
        long ans=0;
        for (long i=1; i<=n; i*=10) {
            long a=n/i, b=n%i;
            ans += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return ans;
    }
};
