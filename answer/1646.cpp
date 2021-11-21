/*
    0 1 1 1+2 2 2+3 3 3+4 4 4+5
    0 1 2 3.  4 5.  6 7.  8 9
*/
class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        vector<int> dp={0,1};
        int ans=n<2?dp[n]:0;
        for (int i=2; i<=n; ++i) {
            int num=dp[i/2]+(i%2?dp[i/2+1]:0);
            dp.push_back(num);
            ans=max(ans,num);
        }
        return ans;
    }
};