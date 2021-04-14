class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B)
    {
        vector<int> tableB(26,0);
        for (string &b:B) {
            vector<int> t(26,0);
            for (char &c:b) t[c-'a']++;
            for (int i=0; i<26; ++i) tableB[i]=max(tableB[i],t[i]);
        }
        vector<string> ans;
        for (string &a:A) {
            vector<int> t(26,0);
            for (char &c:a) t[c-'a']++;
            bool feasible=true;
            for (int i=0; i<26; ++i) {
                if (tableB[i]>t[i]) {
                    feasible=false;
                    break;
                }
            }
            if (feasible) ans.push_back(a);
        }
        return ans;
    }
};
