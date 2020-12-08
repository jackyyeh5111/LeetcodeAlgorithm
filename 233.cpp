/***** Second Visit *****/
/*
    dp[0]  0-9            10*0+1=1
    dp[1]  10-99          10*1+10=20
    dp[2]  100-999        10*20+100=300
    dp[3]  1000-9999      10*300+1000=4000
    dp[4]  10000-99999    10*4000+10000=50000

    133
    dp[1]+34+dp[0]*4+10

    233
    dp[1]*2+100+dp[0]*3+10+(3>1)

    2233
    dp[2]*2+1000+dp[1]*2+100+dp[0]*3+10+(3>1)

    2033
    dp[2]*2+1000+dp[0]*3+10+(3>1)
*/
class Solution {
public:
    int countDigitOne(int n) {
        int m=n,t=1;
        vector<long> table{0,1};
        while(m/10) {
            t*=10;
            table.push_back(table.back()*10+t);
            m/=10;
        }
        int ans=0, i=0, r=0, k=0;
        while (n) {
            int r=n%10;
            ans+=(r*table[i]+(r>1?pow(10,i):(r==1?k+1:0)));
            k+=r*pow(10,i);
            i++;
            n/=10;
        }
        return ans;
    }
};

/***** First Visit *****/
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
