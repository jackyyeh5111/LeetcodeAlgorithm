/*
    4 -> 2+1 3*2/2
    5 -> 3+2+1 4*3/2
    6 -> 4+3+2+1 5*4/2
    find the max length of consecutive arithmetic slice and do calculation for possible combination
    T:O(n)/S:O(1)
    -----
    dp[i] denotes max length of arithmetic slice ends up to A[i];
    return dp[0]+...+dp[n-1]
    T:O(n)/S:O(n)
    -----
    Reduce 1-d dp to 0-d dp
    T:O(n)/S:O(1)
*/

// 0-d DP T:O(n)/S:O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int n=A.size(), ans=0, prev=0;
        for (int i=2; i<n; ++i) {
            if (A[i]-A[i-1]==A[i-1]-A[i-2])
                ans+=(++prev);
            else prev=0;
        }
        return ans;
    }
};

// 1-d DP T:O(n)/S:O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int n=A.size(), ans=0;
        vector<int> dp(n,0);
        for (int i=2; i<n; ++i) {
            if (A[i]-A[i-1]==A[i-1]-A[i-2])
                dp[i]=dp[i-1]+1;
            ans+=dp[i];
        }
        return ans;
    }
};

// greedy calc T:O(n)/S:O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int n=A.size(), i=0, ans=0;
        while (i<n) {
            int j=i+1;
            while (j<n-1&&(A[j]-A[j-1])==(A[j+1]-A[j])) j++;
            ans+=((j-i)*(j-i-1)/2);
            if (j!=i+1) i=j+1;
            else i=j;
        }
        return ans;
    }
};
