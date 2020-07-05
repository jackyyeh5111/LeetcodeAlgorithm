/*
    Actually both algos are kind of DP. (memorize incremental small problems
    then utilize these to solve large problem.) The key is to take a forward checking to avoid TLE. Otherwise time complexity are the same.
    w.o. set/union T:O(n^2*m), S:O(n), where n=len(s), m=len(wordDict)
    w. set/union T:O(n^2), S:O(n+m), where n=len(s), m=len(wordDict)
*/

/****************** Post DFS solution ******************/
/* This is a top-down dfs with forward check.*/
class Solution {
public:
    unordered_map<string,vector<string>> cache;
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        return dfs(s,wordSet);
    }

    vector<string> dfs(string &s, unordered_set<string> &wordSet)
    {
        if (cache.find(s)!=cache.end()) return cache[s];
        vector<string> result;
        if (wordSet.find(s)!=wordSet.end()) result.push_back(s);
        for (int i=1; i<s.size(); ++i) {
            string sub=s.substr(i);
            if (wordSet.find(sub)!=wordSet.end()){
                string before=s.substr(0,i);
                vector<string> prevs=dfs(before,wordSet);
                for (string prev:prevs){
                    result.push_back(prev+" "+sub);
                }
            }
        }
        cache[s]=result;
        return result;
    }
};

/****************** problem 139. DP ******************/
/* This is a top-down dfs without forward check.*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        /*
            try to reduce to problem 139.
            DP, save possible path to s[i] in each position i.
        */
        vector<vector<string>> dp(s.length()+1,vector<string>{});
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        dp[0].push_back("");
        for (int i=1; i<=s.length(); ++i) {
            for (int j=0; j<i; ++j) {
                if (dp[j].size()==0) continue;
                /*Add forward check*/
                string sub=s.substr(j,i-j);
                if (wordSet.find(sub)!=wordSet.end()){
                    for(string word:dp[j]){
                        if(word=="")
                            dp[i].push_back(sub);
                        else
                            dp[i].push_back(word+" "+sub);
                    }
                }
            }
        }

        return dp[s.length()];
    }
};
