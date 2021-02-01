/*
    n=3, ans=0
    1 ans<<1+1=1
    10 ans<<2+2=6
    11 ans<<2+3=27
*/
class Solution {
public:
    int concatenatedBinary(int n)
    {
        long ans=0,mod=pow(10,9)+7;
        for (int i=1; i<=n; ++i) {
            int l=0, r=32;
            while(l<=r) {
                int mid=(l+r)/2;
                if ((1<<mid)>i) r=mid-1;
                else l=mid+1;
            }
            ans=(ans*(1<<l)+i)%mod;
        }
        return ans;
    }
};
