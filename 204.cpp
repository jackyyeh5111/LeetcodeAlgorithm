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
