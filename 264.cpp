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
