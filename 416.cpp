/*
    w= 14,9,8,4,3,2
    capacity= 40/2
    dp[i][j] means with items 0~i, if we can sum up to j or not.
    >> Reduce to 1-d DP.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int total=0,target=0;;
        for(int num:nums) total+=num;
        if(total%2!=0) return false;
        else target=total/2;
        vector<bool> dp(total+1, false);
        dp[0]=true;
        for (int num:nums) {
            for (int k=target; k>=num; --k) {
                dp[k]=dp[k]||dp[k-num];
            }
        }
        return dp[target];
    }
};
