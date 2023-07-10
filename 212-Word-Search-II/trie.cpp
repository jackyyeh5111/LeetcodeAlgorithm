/* 
    Time Limit Exceeded!

           2.   2    1   
    root-> e -> a -> t
                  -> r
                     1
 
    Recursively pruining!
 */
class TrieNode {
    public: 
        const int NUM_ALPHABETIC = 26;
        TrieNode(){
            next.resize(NUM_ALPHABETIC, nullptr);
            is_end = false;
            count = 0;
        }
        vector<TrieNode*> next;
        int count;
        bool is_end;
};

class Solution {
public:
    unordered_set<string> ans;
    vector<vector<bool>> visited;
    TrieNode *root;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init Trie
        root = new TrieNode();
        for (string word : words) {
            TrieNode *node = root;          
            for (char ch : word) {
                if (!node->next[ch - 'a']) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
                ++(node->count);
            }
            node->is_end = true;
        }

        int num_r = board.size();
        int num_c = board[0].size();
        visited.resize(num_r, vector<bool>(num_c));
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                visited[r][c] = true;
                dfs(board, r, c, root, "");
                visited[r][c] = false;
            }
        }

        vector<string> ret;
        for (auto it = ans.begin(); it != ans.end(); ++it)
            ret.push_back(*it);
        return ret;
    }
    void dfs(const vector<vector<char>>& board, int r, int c, TrieNode *node, string word) {
        char ch = board[r][c];
        TrieNode *next_node = node->next[ch - 'a'];
        if (!next_node)
            return;
        if (next_node->count == 0)
            return;
        
        word += ch;
        if (next_node->is_end) {
            ans.insert(word);    
            next_node->is_end = false;
            prune(word); // prune recursively
        }

        int numR = board.size();
        int numC = board[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            if (nextR < 0 || nextC < 0 || nextR >= numR || nextC >= numC)
                continue;
            if (visited[nextR][nextC])
                continue;

            visited[nextR][nextC] = true;
            dfs(board, nextR, nextC, next_node, word);
            visited[nextR][nextC] = false;
        }
    }
    void prune(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            node = node->next[ch - 'a'];
            --(node->count);
        }
    }
    
};

/* 
    Time Limit Exceeded!

    不需要複製 visited 多遍！
 */
class TrieNode {
    public: 
        const int NUM_ALPHABETIC = 26;
        TrieNode(){
            next.resize(NUM_ALPHABETIC, nullptr);
            is_end = false;
            num_next = 0;
        }
        vector<TrieNode*> next;
        int num_next;
        bool is_end;
};

class Solution {
public:
    unordered_set<string> ans;
    vector<vector<bool>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init Trie
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *node = root;          
            for (char ch : word) {
                if (!node->next[ch - 'a']) {
                    node->next[ch - 'a'] = new TrieNode();
                    ++(node->num_next);
                }
                node = node->next[ch - 'a'];
            }
            node->is_end = true;
        }

        int num_r = board.size();
        int num_c = board[0].size();
        visited.resize(num_r, vector<bool>(num_c));
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                visited[r][c] = true;
                dfs(board, r, c, root, "");
                visited[r][c] = false;
            }
        }

        vector<string> ret;
        for (auto it = ans.begin(); it != ans.end(); ++it)
            ret.push_back(*it);
        return ret;
    }
    void dfs(const vector<vector<char>>& board, int r, int c, TrieNode *node, string word) {
        char ch = board[r][c];
        if (!node->next[ch - 'a'])
            return;
        
        TrieNode *next_node = node->next[ch - 'a'];
        word += ch;
        if (next_node->is_end) {
            ans.insert(word);
            if (next_node->num_next == 0) {
                node->next[ch - 'a'] = nullptr;
                --(node->num_next);
                return;
            }
        }

        int numR = board.size();
        int numC = board[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            if (nextR < 0 || nextC < 0 || nextR >= numR || nextC >= numC)
                continue;
            if (visited[nextR][nextC])
                continue;

            visited[nextR][nextC] = true;
            dfs(board, nextR, nextC, next_node, word);
            visited[nextR][nextC] = false;
        }
    }
    
};

/* 
    Time Limit Exceed!

    Improve by adding num_next attribute.
 */
class TrieNode {
    public: 
        const int NUM_ALPHABETIC = 26;
        TrieNode(){
            next.resize(NUM_ALPHABETIC, nullptr);
            is_end = false;
            num_next = 0;
        }
        vector<TrieNode*> next;
        int num_next;
        bool is_end;
};

class Solution {
public:
    unordered_set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init Trie
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *node = root;          
            for (char ch : word) {
                if (!node->next[ch - 'a']) {
                    node->next[ch - 'a'] = new TrieNode();
                    ++(node->num_next);
                }
                node = node->next[ch - 'a'];
            }
            node->is_end = true;
        }

        int num_r = board.size();
        int num_c = board[0].size();
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                vector<vector<bool>> visited(num_r, vector<bool>(num_c));
                dfs(board, r, c, root, visited, "");
            }
        }

        vector<string> ret;
        for (auto it = ans.begin(); it != ans.end(); ++it)
            ret.push_back(*it);
        return ret;
    }
    void dfs(const vector<vector<char>>& board, int r, int c, TrieNode *node, vector<vector<bool>> visited, string word) {
        if (visited[r][c])
            return;
        char ch = board[r][c];
        if (!node->next[ch - 'a'])
            return;
        
        TrieNode *next_node = node->next[ch - 'a'];
        visited[r][c] = true;
        word += ch;
        if (next_node->is_end) {
            ans.insert(word);
            if (next_node->num_next == 0) {
                node->next[ch - 'a'] = nullptr;
                --(node->num_next);
                return;
            }
        }
        

        int numR = board.size();
        int numC = board[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            if (nextR < 0 || nextC < 0 || nextR >= numR || nextC >= numC)
                continue;
            dfs(board, nextR, nextC, next_node, visited, word);
        }
    }
    
};

/* 
    Time Limit Exceed!
 */
class TrieNode {
    public: 
        const int NUM_BRANCH = 26;
        TrieNode(){
            next.resize(NUM_BRANCH, nullptr);
            is_end = false;
        }
        vector<TrieNode*> next;
        bool is_end;
};

class Solution {
public:
    unordered_set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init Trie
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *node = root;          
            for (char ch : word) {
                if (!node->next[ch - 'a']) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->is_end = true;
        }

        int num_r = board.size();
        int num_c = board[0].size();
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                vector<vector<bool>> visited(num_r, vector<bool>(num_c));
                dfs(board, r, c, root, visited, "");
            }
        }

        vector<string> ret;
        for (auto it = ans.begin(); it != ans.end(); ++it)
            ret.push_back(*it);
        return ret;
    }
    void dfs(const vector<vector<char>>& board, int r, int c, TrieNode *node, vector<vector<bool>> visited, string word) {
        if (visited[r][c])
            return;
        char ch = board[r][c];
        if (!node->next[ch - 'a'])
            return;
        
        node = node->next[ch - 'a'];
        visited[r][c] = true;
        word += ch;
        if (node->is_end)
            ans.insert(word);
        
        int numR = board.size();
        int numC = board[0].size();
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            if (nextR < 0 || nextC < 0 || nextR >= numR || nextC >= numC)
                continue;
            dfs(board, nextR, nextC, node, visited, word);
        }
    }
    
};

/* 
    root -> e -> a -> t

 */









