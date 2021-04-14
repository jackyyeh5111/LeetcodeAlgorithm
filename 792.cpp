class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        unordered_map<char,vector<int>> indices;
        for (int i=0; i<s.length(); ++i)
            indices[s[i]].push_back(i);

        int ans=0;
        for (string &word:words)
            ans+=isValid(indices,word);

        return ans;
    }


    bool isValid(unordered_map<char,vector<int>> &indices, string word)
    {
        int cur=-1;
        for (char &c:word) {
            auto it=lower_bound(indices[c].begin(),indices[c].end(),cur+1);
            if (it==indices[c].end()) return false;
            cur=*it;
        }
        return true;
    }
};
