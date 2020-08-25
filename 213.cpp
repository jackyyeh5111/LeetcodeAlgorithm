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
