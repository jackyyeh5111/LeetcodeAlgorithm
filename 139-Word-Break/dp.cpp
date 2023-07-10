class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int N = s.size();
        vector<bool> dp(N);
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (!dp[i]) 
                    continue;
                string substr = s.substr(i, j - i + 1);
                if (us.find(substr) == us.end())
                    continue;
                dp[j + 1] = true;
            }
        }
        return dp[N];
    }
};
/* 
    leetcode
    T        T
 */