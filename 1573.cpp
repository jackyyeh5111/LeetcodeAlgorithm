/*
    "10101"
     ^ ^ ^
    "11000101101"
      ^      ^
    a=cq1+x
    b=cq2+y

*/
class Solution {
public:
    int numWays(string s) {
        long n=s.length(), k=0;
        int mod=1e9+7;
        for (char &c:s) k+=c=='1';
        if (k%3!=0) return 0;
        else if (k==0) return n>=3?((n-1)*(n-2)/2)%mod:0;
        k/=3;
        int t=0,cur=0,a=1,b=1;
        for (char &c:s) {
            cur+=c=='1';
            if (c=='0'&&cur>=k&&cur<k+1) a++;
            else if (c=='0'&&cur>=2*k&&cur<2*k+1) b++;
        }
        long ans=((long)a*(long)b)%mod;
        return ans;
    }
};
