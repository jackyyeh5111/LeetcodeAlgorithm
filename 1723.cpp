/*
    Directly thought:
    divide into k group with average weighting.
    -----
    This is a multi-0/1 knapsack problem, which is an NP complete problem.
    T:O(n^2 * 2^n)
    -----
    back tracking
    T:O(n^k)
*/
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        int n=jobs.size();
        vector<int> sums(1<<n);
        for (int i=0; i<(1<<n); ++i) {
            for (int x=0; x<n; ++x) {
                if ((1<<x)&i) sums[i]+=jobs[x];
            }
        }
        
        vector<vector<int>> dp(k+1,vector<int>(1<<n,0));
        for (int i=0; i<(1<<n); ++i) dp[1][i]=sums[i];
        for (int x=2; x<=k; ++x) {
            for (int i=1; i<(1<<n); ++i) {
                dp[x][i]=dp[x-1][i];
                for (int ti=i; ti; ti=(ti-1)&i) {
                    dp[x][i]=min(dp[x][i],max(sums[ti],dp[x-1][i-ti]));
                }
            }
        }
        return dp[k][(1<<n)-1];
    }
};

// back tracking T:O(n^k * klogk)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        if (k>=jobs.size()) 
            return *max_element(jobs.begin(),jobs.end());
        int ans=INT_MAX;
        vector<int> workers(k,0);
        dfs(jobs,workers,0,ans);
        return ans;   
    }
    
    void dfs(vector<int> &jobs, vector<int> workers, int idx, int &ans)
    {
        sort(workers.begin(),workers.end());
        if (idx>=jobs.size()) {
            ans=min(ans,workers.back());
            return;
        }
        for (int i=0; i<workers.size(); ++i) {
            if (i>0&&workers[i]==workers[i-1]) continue;
            if (workers[i]+jobs[idx]<ans) {
                workers[i]+=jobs[idx];
                dfs(jobs,workers,idx+1,ans);
                workers[i]-=jobs[idx];
            }
        }
    }
};