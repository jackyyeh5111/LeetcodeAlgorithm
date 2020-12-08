/***** Second Visit *****/
/*
    Array:
    1. 2 ptr solution (greedy)
    2. binary search
    3. 2-D array
      - DP: cumulatively solve the problem. what kind of information of last entry could be used?
      - Greedy: divide & conquer, split the array into small parts
      - Backtracking: enumerate all possible combinations
    -----
    DP solution
    dp[i] denotes min steps to reach position i.
    T:O(n^2)/S:O(n)
    TLE!!! This approach could be used while jump exact num[i].
    -----
    Here we are only ased to jump in a range 0-num[i], which means we could have a moving window, to
    check current max stop position.
    Greedy approach:
    T:O(n)/S:O(1)

*/
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        int start=0,end=0,steps=0;
        if(n<=1) return steps;
        while(end<n) {
            steps++;
            int max_end=end+1;
            for (int i=start; i<=end; ++i) {
                if (i+nums[i]>=n-1) return steps;
                max_end=max(max_end,i+nums[i]);
            }
            start=end+1; end=max_end;
        }
        return steps;
    }
};

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n,n-1); dp[0]=0;
        for (int i=0; i<n; ++i) {
            int k=min(n-1-i,nums[i]);
            for (int j=1; j<=k; ++j) {
                dp[i+j]=min(dp[i]+1,dp[i+j]);
            }
            // for(int c:dp) cout<<c<<",";
            // cout<<endl;
        }
        return dp[n-1];
    }
};

/***** First Visit *****/
/****************** 2 pointers to record each step ******************/
class Solution {
public:
    // T:O(n)
    int jump(vector<int>& nums) {
        int start = 0; int end = 0; int steps = 0;
        while (end<nums.size()-1) {
            steps++;
            int max_end = end + 1;
            for (int i=start; i<=end; ++i) {
                if (i+nums[i]>=nums.size()-1) return steps;
                max_end = max(i+nums[i], max_end);
            }
            start = end + 1; end = max_end;
        }
        return steps;
    }
};

/****************** back tracking ******************/
/****************** TLE ******************/
class Solution {
public:
    int steps=INT_MAX;
    // worst case T:O(^2)
    int jump(vector<int>& nums)
    {
        // back tracking, assume always can reach last one.
        jump(nums, 0, 0);
        return steps;
    }

    void jump(vector<int>& nums, int current, int maxStep)
    {
        if (current >=nums.size()) return;
        if (current == nums.size()-1) steps=min(maxStep,steps);


        for (int i=nums[current]; i>=1; --i) {
            jump(nums, current+i, maxStep+1);
        }
        return ;
    }
};
