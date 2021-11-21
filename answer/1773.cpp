class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int ans=0;
        for (auto item:items) {
            if ("type"==ruleKey&&item[0]==ruleValue) ans++;
            else if ("color"==ruleKey&&item[1]==ruleValue) ans++;
            else if ("name"==ruleKey&&item[2]==ruleValue) ans++;
        }
        return ans;
    }
};
