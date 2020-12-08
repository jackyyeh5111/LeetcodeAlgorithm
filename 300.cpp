/***** Third Visit *****/
/*
    Longest Increasing Subsequence
    Find LCS with nums and sorted nums
    This will get longest increasing nums with larger or equal values.
    DP: T:O(n^2)/S:O(n^2)
    -----
    1-D dp
    dp[i] denotes the length of LIS
    dp[i]=max(dp[i],dp[j]+1) where nums[j]<nums[i]&&j<i
    LIS may occur in the mid of nums, thus we need to check current max answer while looping.
    T:O(n^2)/S:O(n)
    -----
    BIS ( Bucket Increasing Sequence)
    maintain the best nums with increasing order.
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int num:nums) {
            auto idx=lower_bound(ans.begin(),ans.end(),num);
            if (idx==ans.end()) ans.push_back(num);
            else *idx=num;
        }
        return ans.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), ans=1;
        vector<int> dp(n,1);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    sorting then reduce to LCSequence
    T:O(nlogn+n^2)/S:O(n)
    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+nums[i]==sorted[j]
    WRONG THOUGH because we cannot handle INCREASING order.
    Or we should apply vector to save each possible increasing length through DP.
    -----
    Use DP for nested 2 ptr checking
    T:O(n^2)/S:O(n)
    -----
    Best Increasing Subsequence of Length K
    BIS(k) with binary search since that BIS is an increasing order.
    During each iteration, binary search on k length of BIS.
    T:O(nlogn)/S:O(n)
*/

// BIS(k)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size(), ans=0;
        vector<int> dp(n,0);
        auto end=dp.begin();
        for (int num:nums) {
            auto idx=lower_bound(dp.begin(),end,num);
            *idx=num;
            if (idx==end) {ans++; end++;}
        }
        return ans;
    }
};

// 1-D DP with T:O(n^2), nested i,j.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size(), ans=1;
        vector<int> dp(n,1);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);
                ans=max(dp[i],ans);
            }
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    2 3 5 7 9 10 18 101
    2 4 3 5 1 0. 7. 6
    ---------

    LCS (Longest Common Subsequence)
    DP problem
    compare: vec & sorted vec
    dp[i][j]
        i!=j max(dp[i-1][j],dp[i][j-1])
        i==j dp[i-1][j-1]+1
    T:O(nlogn+n^2)/S:O(n^2)
    ---------
    Could improve DP approach into 1-D DP
    T:O(nlogn+n^2)/S:O(n)
    ---------
    Another 1-D DP approach
    dp[i] represents the length of the longest increasing subsequence possible
    considering the array elements upto the i th index only ,by necessarily
    including the i th element.

    During each i th element, find the largest LCS. dp[i]=largest+1
    T:O(n^2)/S:O(n)
    ----------
    DP with binary search
    This dp array is meant to store the increasing subsequence formed by
    including the currently encountered element. While traversing the nums
    array, we keep on filling the dp array with the elements encountered so far.
    T:O(nlogn)/S:O(n)
*/

/************* 2-D DP with LCSequence(TLE) *************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        vector<vector<pair<int,int>>> dp(n+1,
            vector<pair<int,int>>(n+1,make_pair(0,INT_MIN)));
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (nums[i-1]==sorted[j-1]&&dp[i-1][j-1].second<nums[i-1])
                    dp[i][j]=make_pair(dp[i-1][j-1].first+1,nums[i-1]);
                else {
                    pair<int,int> prev_max;
                    if (dp[i-1][j].first<dp[i][j-1].first)
                        prev_max=dp[i][j-1];
                    else if (dp[i-1][j].first>dp[i][j-1].first)
                        prev_max=dp[i-1][j];
                    else
                        prev_max=dp[i-1][j].second>dp[i][j-1].second?dp[i][j-1]:dp[i-1][j];
                    dp[i][j]=prev_max;
                }
            }
        }
        return dp[n][n].first;
    }
};

/************* 1-D DP with LCSequence(AC) *************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        vector<pair<int,int>> dp(n+1,make_pair(0,INT_MIN));
        for (int i=1; i<=n; ++i) {
            pair<int,int> left_top=dp[0];
            for (int j=1; j<=n; ++j) {
                auto tmp=dp[j];
                if (nums[i-1]==sorted[j-1]&&left_top.second<nums[i-1])
                    dp[j]=make_pair(left_top.first+1,nums[i-1]);
                else {
                    pair<int,int> prev_max;
                    if (dp[j].first<dp[j-1].first)
                        prev_max=dp[j-1];
                    else if (dp[j].first>dp[j-1].first)
                        prev_max=dp[j];
                    else
                        prev_max=dp[j].second>dp[j-1].second?dp[j-1]:dp[j];
                    dp[j]=prev_max;
                }
                left_top=tmp;
            }
        }
        return dp[n].first;
    }
};

/************* Another 1-D DP with finding LIS so far (AC) *************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n,0);
        dp[0]=1; int ans=1;
        for (int i=1; i<n; ++i) {
            int max_length=0;
            for (int j=0; j<i; ++j) {
                if (nums[j]<nums[i])
                    max_length=max(max_length,dp[j]);
            }
            dp[i]=max_length+1;
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};

/**** 1-D DP with finding LIS so far and improved by binary search (AC) ****/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size(), ans=0;
        vector<int> dp(n);
        auto end=dp.begin();
        for (int num:nums) {
            auto idx=lower_bound(dp.begin(),end,num);
            *idx=num;
            if (idx==end) {ans++; end++;}
            // for(int x:dp) cout<<x<<",";
            // cout<<endl;
        }
        return ans;
    }
};
