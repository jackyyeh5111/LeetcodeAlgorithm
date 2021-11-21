class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        int ans=INT_MAX;
        for (auto base:baseCosts) {
            dfs(toppingCosts,0,0,target,ans,base);
        }
        return ans;
    }

    void dfs(vector<int>& toppingCosts, int idx, int cur, int target, int &ans,int base)
    {
        if (ans==INT_MAX||abs(cur+base-target)<abs((ans-target))) ans=cur+base;
        if (cur+base>=target) return;
        if (idx>=toppingCosts.size()) return;
        for (int i=0; i<=2; ++i)
            dfs(toppingCosts,idx+1,cur+toppingCosts[idx]*i,target,ans,base);

    }
};
