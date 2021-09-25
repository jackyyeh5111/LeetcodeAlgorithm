/***** Fifth Visit *****/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int prevprev=0,prev=nums[0],n=nums.size();
        for (int i=1; i<n; ++i) {
            int t=max(prev,prevprev+nums[i]);
            prevprev=prev; prev=t;
        }
        return max(prevprev,prev);
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1,0); dp[1]=nums[0];
        for (int i=2; i<=n; ++i) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp.back();
    }
};

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return 0;
        int prevprev=0, prev=nums[0];
        for (int i=1; i<n; ++i) {
            int cur=max(prev,prevprev+nums[i]);
            prevprev=prev; prev=cur;
        }
        return prev;
    }
};

/***** Third Visit *****/
/*
    reduce 1-d to constant space
    T:O(n)/S:O(1)
    -----
    1-d dp solution
    dp[i]=max(dp[i-1], dp[i-2]+nums[i])
*/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        int prevprev=0, prev=0;
        for (int i=0; i<n; ++i) {
            int cur=max(prev,prevprev+nums[i]);
            prevprev=prev;
            prev=cur;
        }
        return max(prevprev,prev);
    }
};

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size(), ans=0;
        if (n==0) return ans;
        vector<int> dp(n,0);
        dp[0]=nums[0];
        ans=nums[0];
        for (int i=1; i<n; ++i) {
            if (i==1) dp[i]=max(nums[i],dp[0]);
            else dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    House robbing
    for each position i, we have profit that
        dp[i]=max(dp[i-2]+profit[i],dp[i-1]), where dp[i] denots max profit in
        position i.
    T:O(n)/S:O(n)
    -----
    Then we can reduce 1-D dp solution to constant space complexity.
    T:O(n)/S:O(1)
*/
/* 1-D DP */
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for (int i=0; i<n; ++i) {
            dp[i+2]=max(dp[i+1],dp[i]+nums[i]);
        }
        return dp[n+1];
    }
};

/* 0-D DP */
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for (int i=0; i<n; ++i) {
            dp[i+2]=max(dp[i+1],dp[i]+nums[i]);
        }
        return dp[n+1];
    }
};

/***** First Visit *****/
/****************** T:O(n), S:O(1) DP ******************/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        /*
            100 1 1 100
            dp[i] denotes max profit at position i.
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
            keep tracking if current max profit contains current num or not.
            ---------
            Actually we dont need to care about if contiguous robbing since our
            recursive function: max(dp[i-1],dp[i-2]+num)
            ---------
            Then we can reduce S:O(n) to S:O(1)
        */
        // T:O(n), S:O(n)
        int n=nums.size();
        int prev=0, cur=0;
        for (int i=0; i<n; ++i) {
            int tmp=max(cur,prev+nums[i]);
            prev=cur;
            cur=tmp;
        }
        return cur;
    }
};

/****************** T:O(n), S:O(n) DP w.o. checking ******************/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        /*
            100 1 1 100
            dp[i] denotes max profit at position i.
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
            keep tracking if current max profit contains current num or not.
            ---------
            Actually we dont need to care about if contiguous robbing since our
            recursive function: max(dp[i-1],dp[i-2]+num)
        */
        // T:O(n), S:O(n)
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for (int i=2; i<=n; ++i) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};

/****************** T:O(n), S:O(n) DP w.o. checking ******************/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        /*
            100 1 1 100
            dp[i] denotes max profit at position i.
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
            keep tracking if current max profit contains current num or not.
        */
        // T:O(n), S:O(n)
        int n=nums.size();
        vector<pair<int,bool>> dp(n+1,make_pair(0,false));
        for (int i=1; i<=n; ++i) {
            if (!dp[i-1].second) dp[i]=make_pair(dp[i-1].first+nums[i-1],true);
            else {
                dp[i]=make_pair(
                    max(dp[i-1].first,dp[i-2].first+nums[i-1]),
                    dp[i-2].first+nums[i-1]>dp[i-1].first);
            }
        }
        return dp[n].first;

    }
};
