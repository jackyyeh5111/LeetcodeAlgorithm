class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<pair<int,int>> s;
        vector<int> ans;
        for (int i=0; i<T.size(); ++i) {
            ans.push_back(0);
            while (!s.empty()&&s.top().first<T[i]) {
                auto p=s.top(); s.pop();
                ans[p.second]=i-p.second;
            }
            s.push({T[i],i});
        }
        return ans;
    }
};
