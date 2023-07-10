/* 
    Correct answer. But got Time Limit Exceeded.
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> wordsStartsWith;
        for (auto word : wordDict)
            wordsStartsWith[word[0]].push_back(word);

        vector<bool> visited(s.size() + 1);
        queue<int> que;
        que.push(0);
        while(!que.empty()) {
            int pos = que.front();
            if (pos == s.size())
                return true;
            que.pop();
            visited[pos] = true;
            for (string word : wordsStartsWith[s[pos]]) {
                int N = word.size();
                if (pos + N > s.size() || word != s.substr(pos, N))
                    continue;
                if (visited[pos + N])
                    continue;
                que.push(pos + N);
            }
        }
        return false;
    }
};

/* 
    bc
    a b c

    t t f
    queue: [0] // starting pos
    queue: [1, 2]

    dict = ["a", "ab", "b"]
 */