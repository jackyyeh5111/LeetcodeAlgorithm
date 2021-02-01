class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> visited;
        for (auto p:adjacentPairs) {
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        vector<int> ans;
        int start;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            if (it->second.size()!=1) continue;
            start=it->first;
            break;
        }
        dfs(mp,visited,start,ans);
        return ans;
    }

    void dfs(unordered_map<int,vector<int>> &mp, unordered_set<int> &visited, int u, vector<int> &ans)
    {
        if (visited.count(u)) return;
        visited.insert(u);
        ans.push_back(u);
        for (int v:mp[u]){
            dfs(mp,visited,v,ans);
        }
    }
};
