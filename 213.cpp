/***** Third Visit *****/
// T:O(n)/S:O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(), lprev=0, lprevprev=0, rprev=0, rprevprev=0;
        if (n==0) return 0;
        else if (n==1)  return nums[0];
        for (int i=1; i<n; ++i) {
            int l=max(lprev, lprevprev+nums[i]);
            lprevprev=lprev; lprev=l;
            int r=max(rprev, rprevprev+nums[n-i-1]);
            rprevprev=rprev; rprev=r;
        }
        return max(max(lprev,lprevprev),max(rprev,rprevprev));
    }
};

/***** Second Visit *****/
/*
    dp[i] denotes the profit robbed so far.
    dp[i]=max(dp[i-1],dp[i-2]+nums[i])
    Note that we cant rob the first and last house
    run from both sides that ignore the house on start position.
    T:O(n)/S:O(n) -> T:O(n)/S:O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return 0;
        else if (n==1) return nums[0];
        int leftprev=0,rightprev=0,left=0,right=0;
        for (int i=1; i<n; ++i) {
            int t1=left;
            left=max(left,leftprev+nums[i]);
            leftprev=t1;
            int t2=right;
            right=max(right,rightprev+nums[n-i-1]);
            rightprev=t2;

        }
        return max(left,right);
    }
};

/***** First Visit *****/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        /*
            [1,2,3,1]
             1 2 3
               2 3 1
            if we have two situation:
                rob first and ignore last one
                rob last and ignore first one
            we can reduce to problem House Robber.
            2 pass: T:O(n), S:O(1)
            -> reduce to 1 pass
        */
        int x=0,prev_x=0,y=0,prev_y=0,ans=0;
        int n=nums.size();
        if (n==1) return nums[0];
        for (int i=0; i<n-1; ++i) {
            if (i==0) {
                x=nums[i];
                y=nums[n-1-i];
                ans=max(x,y);
            }
            else {
                int cur_x=max(x,prev_x+nums[i]);
                prev_x=x; x=cur_x;
                int cur_y=max(y,prev_y+nums[n-1-i]);
                prev_y=y; y=cur_y;
                ans=max(ans,max(cur_x,cur_y));
            }
        }
        return ans;
    }
};
