class Solution {
public:
    int arrangeCoins(int n)
    {
        /*
            Use for loop to sum untilsum<n, then return i, which is the iterative counts.
            T: O(n), S:O(1), NOTICE INT OVERFLOW.
            int sum=0; int idx=0;
            while (sum<=n-idx-1) {
                idx++;
                sum+=idx;
            }
            return idx;
            -----------------------------
            use binary search
            T:O(logn),S:O(1)
        */
        int l=0, r=n;
        while(l<=r) {
            long mid=(l+r)/2;
            long coins=(mid+1)*mid/2;
            if(coins==n) return mid;
            else if (coins>n) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};
