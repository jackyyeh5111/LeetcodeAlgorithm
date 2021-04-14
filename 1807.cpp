class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        unordered_map<string,string> table;
        for (auto &k:knowledge) {
            table[k[0]]=k[1];
        }
        string ans=""; int n=s.length();
        for (int i=0; i<n; ++i) {
            if (s[i]!='(') ans+=s[i];
            else {
                int j=i+1; string key="";
                while (j<n&&s[j]!=')') key+=s[j++];
                i=j;
                if (table.count(key)==0) ans+='?';
                else ans+=table[key];
            }
        }
        return ans;
    }
};
