/* 
    Backtrace
 */
class Solution {
public:
    unordered_map<string, vector<string>> adjs;
    int ans = INT_MAX;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1) build connected graph
        buildGraph(wordList);

        // 2) backtrace with dfs
        unordered_set<string> visited;
        dfs(beginWord, endWord, 1, visited);
        return ans == INT_MAX ? 0 : ans;
    }
    void dfs(const string& word, const string& endWord, int cnt, unordered_set<string> &visited){
        if (word == endWord) {
            ans = min(ans, cnt);
            return;
        }
        if (visited.count(word)) return;

        // backtrace
        int len_word = word.size();
        for (int i = 0; i < len_word; i++) {
            string encode = word;
            encode[i] = '*';
            
            visited.insert(word);
            for (string& next_word : adjs[encode]) {
                dfs(next_word, endWord, cnt+1, visited);
            }
            visited.erase(word);
        }
    }
    void buildGraph(const vector<string>& wordList) {
        int len_word = wordList.at(0).size();
        for (const string& word : wordList) {
            for (int i = 0; i < len_word; i++) {
                string encode = word;
                encode[i] = '*';
                adjs[encode].push_back(word);
            }
        }
    }
};

/* 
    abc abd
    ["abd"]

    adj_words {
        "*ot": ["hot", "dot"]
        "h*t": ["hot", "hit"]
        "ho*": ["hot"]
    }
 */