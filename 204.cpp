/***** Fifth Visit *****/
/*
    i*i + i*k -> n equals to
    i + k ->n/i
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int countPrimes(int n)
    {
        vector<bool> dp(n,1);
        int ans=0;
        for (int i=2; i<n; ++i) {
            ans+=dp[i];
            int j=i, k=n/i;
            while(j<=k) {
                dp[j*i]=false;
                j++;
            }
        }
        return ans;
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> table(n,1);
        int ans=n-2;
        for (int i=2; i<n; ++i) {
            long k=(long)i*(long)i;
            while (k<(long)n) {
                ans-=table[k];
                table[k]=0;
                k+=(long)i;
            }
        }
        return max(ans,0);
    }
};

/***** Third Visit *****/
class Solution {
public:
    int countPrimes(int n)
    {
        n--;
        if (n<2) return 0;
        int ans=0;
        vector<int> dp(n+1,1);
        for (int i=2; i<=n; ++i) {
            if (dp[i]==0) continue;
            ans++;
            int j=i, k=n/i;
            while (j<=k) {
                dp[j*i]=0; j++;
            }
        }
        return ans;
    }
};

/***** Second Visit *****/
class Solution {
public:
    int countPrimes(int n)
    {
        vector<bool> primes(n,1);
        int ans=0;
        for (int i=2; i<n; ++i) {
            if (!primes[i]) continue;
            ans++;
            long k=(long)i*(long)i;
            while (k<n) {
                primes[k]=0;
                k+=(long)i;
            }
        }
        return ans;
    }
};

/***** First Visit *****/
// Eratosthenes
// T:O(nlogn), T(n)=n/2+n/3+n/5+...=n(1/2+1/3+1/5+...)=nO(logn)
class Solution {
public:
    int countPrimes(int n)
    {
        vector<int> primes(n,1);
        int count=0;
        for (int i=2; i<n; ++i) {
            if (primes[i]==0) continue;
            count++;
            long k=(long)i*(long)i;
            while(k<n) {
                primes[k]=0;
                k+=(long)i;
            }
        }
        return count;
    }
};
