/***** Third Visit *****/
/*
    1 1 2 3 5 8 13
    ^ ^
    p c
*/
class Solution {
public:
    int climbStairs(int n)
    {
        int prev=1,cur=1;
        for (int i=2;i<=n; ++i) {
            int t=cur;
            cur+=prev;
            prev=t;
        }
        return cur;
    }
};

/***** Second Visit *****/
/*
    recursive f(n)=f(n-1)+f(n-2)
    T:O(2^n)/S:(n) depth of recursion
    -----
    1-d dp
    T:O(n)/S:O(n)
    -----
    reduce space complexity of 1-d dp
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        int prev=1,prevprev=1;
        for(int i=2; i<=n; ++i) {
            int c=prev+prevprev;
            prevprev=prev;
            prev=c;
        }
        return prev;
    }
};

/***** First Visit *****/
class Solution {
public:
    int climbStairs(int n)
    {
        // typical fibnoci number problem
        // we can have a dp table dp[n] which means distinct ways to get n.
        // then we have induction: dp[n-1]+dp[n-2]
        // now we see its fibnoci.
        vector<int> dp(n+1,0);
        dp[0]=1; dp[1]=1;
        for (int i=2; i<=n; ++i) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
