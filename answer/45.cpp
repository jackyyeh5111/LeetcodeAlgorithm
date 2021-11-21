/***** Fifth Visit *****/
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int l=0,r=0,step=0;
        while (r<nums.size()-1) {
            int k=r;
            for (int i=l; i<=r; ++i)
                k=max(k,nums[i]+i);
            if (k==r) return -1;
            else step++;
            l=r+1; r=k;
        }
        return step;
    }
};

/***** Fourth Visit *****/
/*
    2 ptr solution
    say we have 2 ptr, l and r.
    l: take 1 step per num
    r: max pos we can reach so far.
    keep update l and r until reach the end.
    For each num, if we can reach farer than r, then step++;
    T:O(n)/S:O(1)
    -----
    TO BE BRIEF, we take BFS in terms of index
      [..............]
    0 ^
    1  ^   ^
    2       ^    ^
    3             ^     ^
    T:O(n)/S:O(1)
*/

/***** Third Visit *****/
/*
    [2,3,1,1,4]
     0 1 2 3 4
     0: 1,2
     1: 2,3,4
     2: 3
     3: 4
     4: -
     Build a graph and apply BFS
     T:O(V+E), E is equal to the sum over 0~n-1
     TLE
     -----
     2 ptr solution.
     Seems like queue traversal. Though we keep tracking next num(node), we
     need to figure out we are in the same level or not.
     T:O(n)/S:O(1)
*/

// BFS TLE
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>> graph(n,vector<int>{});
        vector<bool> visited(n,0);
        for (int i=0; i<n; ++i) {
            for (int j=1; j<=nums[i]; ++j) {
                if (i+j<n) graph[i].push_back(i+j);
            }
        }
        queue<int> q;
        q.push(0);
        int ans=0;
        while (!q.empty()) {
            int k=q.size();
            ans++;
            for (int i=0; i<k; ++i) {
                int u=q.front(); q.pop();
                for (int v:graph[u]) {
                    if (v==n-1) return ans;
                    if (!visited[v]) q.push(v);
                    visited[v]=true;
                }
            }
        }
        return 0;
    }
};

// 2 ptr with same level checking
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size(), l=0, r=0, step=0, prev=-1;
        if (n==1) return 0;
        for (int num:nums) {
            if (l+num>r) {
                if (l>prev) {prev=r; step++;}
                r=l+num;
            }
            if (r>=n-1) return step;
            l++;
        }
        return -1;
    }
};

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
