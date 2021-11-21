/***** Third Visit *****/
/*
    catalan number: 1/(n+1)C^2n_n
    dp: T(n)=2*(T(1)+T(n-1)+T(2)+T(n-2)+...)
            =2*(T(1)+...+T(n-1))
            =3T(n-1)
            =O(3^n)
        S:O(1)
*/
class Solution {
public:
    int numTrees(int n)
    {
        vector<int> dp(n+1,0);
        dp[0]=1; dp[1]=1;
        for(int i=2; i<=n; ++i) {
            int s=0;
            for(int j=0; j<i; ++j)
                s+=dp[j]*dp[i-j-1];
            dp[i]=s;
        }
        return dp[n];
    }
};

class Solution {
public:
    int numTrees(int n)
    {
        return comb(2*n,n)/(n+1);
    }

    long comb(int n, int k)
    {
        vector<long> dp(k+1,1);
        for(int i=1; i<=n-k; ++i) {
           for(int i=1; i<=k; ++i)
               dp[i]+=dp[i-1];
        }
        return dp[k];
    }
};

/***** Second Visit *****/
class Solution {
public:
    int numTrees(int n)
    {
        /*
            catalan number, 1/(n+1)C^2n_n
            using dp
        */
        // vector<long> dp(n+1, 1);
        // for (int i=0; i<n; ++i) {
        //     for (int j=1; j<=n; ++j)
        //         dp[j]+=dp[j-1];
        // }
        // return dp[n]/(n+1);
        /*
        Bn=B0Bn-1+...+Bn-1B0
        */
        if (n<2) return 1;
        vector<int> dp(n+1, 0);
        dp[0]=1; dp[1]=1;
        for (int i=2; i<=n; ++i){
            int count=0;
            for (int j=0; j<=i-1; ++j){
                count+=(dp[j]*dp[i-1-j]);
            }
            dp[i]=count;
        }
        return dp[n];
    }
};

/***** First Visit *****/
class Solution {
public:
    int numTrees(int n)
    {
        /*
        C^n_1+C^n_2=C^n+1_2
        target: C^2n_n
        */
        vector<long> dp(n+1,1);
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                dp[j]+=dp[j-1];
            }
        }
        return dp[n]/(n+1);
    }
};
