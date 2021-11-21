class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
    {
        vector<int> ans(k,0);
        unordered_map<int,unordered_set<int>> cnt;
        for (auto &log:logs) {
            cnt[log[0]].insert(log[1]);
        }
        for (auto it=cnt.begin(); it!=cnt.end(); ++it) {
            ans[it->second.size()-1]++;
        }
        return ans;
    }
};
