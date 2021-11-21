/*
    [[5,4],[6,4],[6,7],[2,3]]
    [[2,3],[5,4],[6,4],[6,7]]

    dp[i] denotes the max doll inside
    T:O(nlogn+n^2)/S:O(n) by dp approach
    -----
    Similar to LIS
     T:O(nlogn)/S:O(n)
*/
// LIS T:O(nlogn)/S:O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end(),[](auto &a, auto &b){
            if (a[0]==b[0]) return a[1]>=b[1];
            else return a[0]<=b[0];
        });
        int n=envelopes.size();
        vector<int> dp;
        for (int i=0; i<n; ++i) {
            auto it=lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            if (it==dp.end()) dp.push_back(envelopes[i][1]);
            else *it=envelopes[i][1];
        }
        return dp.size();
    }
};

// dp T:O(n^2)/S:O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end());
        for (auto a:envelopes) cout<<"["<<a[0]<<","<<a[1]<<"]"<<",";
        int n=envelopes.size();
        vector<int> dp(n,1);
        int ans=1;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (envelopes[i][0]<envelopes[j][0]&&envelopes[i][1]<envelopes[j][1])
                    dp[j]=max(dp[j],dp[i]+1);
                ans=max(ans,dp[j]);
            }
        }
        return ans;
    }
};
