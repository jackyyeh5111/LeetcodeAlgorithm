class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums)
    {
        int i=0,n=nums.size();
        for (auto g:groups) {
            int j=0;
            do {
                int k=i;
                while(k<n&&g[0]!=nums[k]) k++;
                if (n-k<(int)g.size()) return false;
                for (j=0; j<g.size(); ++j) {
                    if (g[j]!=nums[k]) break;
                    k++;
                }
                i=k;
            } while(j!=g.size());
        }
        return true;
    }
};
