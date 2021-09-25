/***** Fourth Visit *****/
/*
    0
    1 0001
    2 0010
    3 0011
    4 0100
    5 0101
*/
class Solution {
public:
    vector<int> countBits(int num)
    {
        int cur=0;
        vector<int> ans(num+1,0);
        for (int i=1; i<=num; ++i) {
            if ((i&(i-1))==0) {
                ans[i]=1;
                cur=i;
            }
            else ans[i]=ans[i-cur]+1;
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    0 --> 0
    1 --> 1
    2 --> 10    2
    3 --> 11    2
    4 --> 100   4
    5 --> 101   4
    6 --> 110   4
    7 --> 111   4
    8 --> 1000  8

    DP!! T:O(n)/S:O(n)

*/
class Solution {
public:
    vector<int> countBits(int num)
    {
        int lb=0;
        vector<int> dp(num+1,0);
        for (int i=1; i<=num; ++i) {
            if ((i&(i-1))==0) lb=i;
            dp[i]=dp[i-lb]+1;
        }
        return dp;
    }
};

/***** second Visit *****/
/*
    0 1 10 11 100 101 110 111 1000 1001 1010 1011
*/
class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0) return {0};
        else if (num==1) return {0,1};
        vector<int> dp(num+1,0); dp[1]=1;
        int t=1;
        for (int i=2; i<=num; ++i) {
            if ((t<<1)==i) t=t<<1;
            dp[i]=dp[i-t]+1;
        }
        return dp;
    }
};

/***** First Visit *****/
class Solution {
/*

The basic logic is:
i -> i & i -1 modify the right-to-left first-met 1 to 0, thus reducing the number of ones by 1
X..X 1 0..0 -> X..X 0 0..0, where X means 0 or 1, X..X means any numbers of X (including zero X )
T:O(n)/S:O(n)
*/

public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
