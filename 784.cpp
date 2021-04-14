/*
    trivial backtrackinng problem.
    T:O(2^n)/S:O(2^n), n denotes number of letter.
*/

// iteration
class Solution {
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans={""};
        for (char c:S) {
            int k=ans.size();
            for (int j=0; j<k; ++j) {
                if (isdigit(c)) ans[j]+=c;
                else {
                    ans.push_back(ans[j]+string(1,toupper(c)));
                    ans[j]+=tolower(c);
                }
            }
        }
        return ans;
    }
};

// backtracking
class Solution {
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        string s="";
        dfs(S,0,s,ans);
        return ans;

    }

    void dfs(string S, int idx, string &s, vector<string> &ans)
    {
        if (idx==S.length()) {
            ans.push_back(s);
            return;
        }
        if (isdigit(S[idx])) {
            s+=S[idx];
            dfs(S,idx+1,s,ans);
            s.pop_back();
        }
        else {
            s+=tolower(S[idx]);
            dfs(S,idx+1,s,ans);
            s.pop_back();
            s+=toupper(S[idx]);
            dfs(S,idx+1,s,ans);
            s.pop_back();
        }
    }
};
