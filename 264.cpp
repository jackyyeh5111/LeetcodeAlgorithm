/***** Fourth Visit *****/
/*
      1 2 3 4
    2     ^
    3   ^
    5 ^
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(1,1);
        int i2=0,i3=0,i5=0;
        while (dp.size()<n) {
            int num2=dp[i2]*2;
            int num3=dp[i3]*3;
            int num5=dp[i5]*5;
            int c=min(num2,min(num3,num5));
            i2+=num2==c;
            i3+=num3==c;
            i5+=num5==c;
            dp.push_back(c);
        }
        return dp.back();
    }
};

/***** Third Visit *****/
/*
    2: 2 4 8 16 32 64 128 256 ...
    3: 3 9 27 ...
    5: 5 25 125 ...

    2: 1 2 3 4 5 6 [7] <-- we cannot multiply non ugly factor.
    3: 1 2 3 4 5
    5: 1 2 3
    1 2 3 4 5 8 9 10 12
    -----
    sample from known ugly number
      1 2
    2 ^
    3 ^
    5 ^
*/
class Solution {
public:
    int nthUglyNumber(int n)
    {
        if (n<=1) return 1;
        int a=0,b=0,c=0;
        vector<int> dp(1,1);
        for (int i=1; i<n; ++i) {
            int ugly=min(dp[a]*2,min(dp[b]*3,dp[c]*5));
            dp.push_back(ugly);
            if (ugly==dp[a]*2) a++;
            if (ugly==dp[b]*3) b++;
            if (ugly==dp[c]*5) c++;
        }
        return dp.back();
    }
};

/***** Second Visit *****/
/*
    1-D dp approach
       1 2 3 4 5
    2:     ^
    3:   ^
    5:   ^
*/
class Solution {
public:
    int nthUglyNumber(int n)
    {
        int a=0,b=0,c=0;
        vector<int> ans(n,1);

        for (int i=1; i<n; ++i) {
            ans[i]=min(2*ans[a],min(3*ans[b],5*ans[c]));
            if ( ans[i] == 2*ans[a] ) a++;
            if ( ans[i] == 3*ans[b] ) b++;
            if ( ans[i] == 5*ans[c] ) c++;
        }
        return ans[n-1];
    }
};

/***** First Visit *****/
class Solution {
public:
    int nthUglyNumber(int n)
    {
        /*
            DP approach Min(L1 * 2, L2 * 3, L3 * 5)
               1 2 3 4 5 6 8 9 10 etc...
            2          ^
            3        ^
            5      ^
        */
        if(n==0) return 1;
        if(n==1) return 1;
        int p2=0,p3=0,p5=0;
        vector<int> ans(n,1);
        for (int i=1; i<n; ++i) {
            ans[i]=min(ans[p2]*2,min(ans[p3]*3,ans[p5]*5));
            if (ans[i]==ans[p2]*2) p2++;
            if (ans[i]==ans[p3]*3) p3++;
            if (ans[i]==ans[p5]*5) p5++;
        }
        return ans[n-1];

    }
};
