/* 
    build a trie
    
    s = "ab"
          ^
    
    s = "acb"

    1. "ab" keep searching in trie
    2. search substr "b" in trie (dfs)
    
    dict = ["ab", "a"]
 */
class TrieNode {
    public: 
        int num_branch = 26;
        vector<TrieNode*> next;
        bool is_end = false;
        TrieNode() {
            next.resize(num_branch, nullptr);
        }
};
class Solution {
public:
    TrieNode* root;
    vector<bool> visited;
    bool wordBreak(string s, vector<string>& wordDict) {
        // build trie
        root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (!node->next[idx])
                    node->next[idx] = new TrieNode();
                node = node->next[idx];
            }
            node->is_end = true;
        }
        
        visited.resize(s.size());
        return dfs(s, 0);
    }
    bool dfs(string s, int pos) {

        visited[pos] = true;

        // traverse trie
        TrieNode* node = root;
        for (int i = pos; i < s.size(); i++) {
            char ch = s[i];
            if (!node->next[ch - 'a'])
                return false;
            
            node = node->next[ch - 'a'];
            if (node->is_end) {
                if (i + 1 == s.size())
                    return true;
                if (!visited[i+1] && dfs(s, i+1))
                    return true;
            }
        }
        return false;
    }
};


/*
    Wrong answer!
        這裡有兩個錯，
        1. visited size
        2. next != node->next

    s = abcd
    dict = ["ab", "abc", "cd"]

           r
        a     c
      b         d
        c
 */
class Solution1 {
  class TrieNode {
   public:
    TrieNode() {
      for (int i = 0; i < 26; ++i) next[i] = nullptr;
      is_end = false;
    }
    TrieNode *next[26];
    bool is_end;
  };

 public:
  vector<bool> visited;
  TrieNode *root;
  bool wordBreak(string s, vector<string> &wordDict) {
    visited.resize(s.size());

    // initialze TrieNode
    root = new TrieNode();
    for (auto word : wordDict) {
      TrieNode *node = root;
      for (char ch : word) {
        TrieNode *next = node->next[ch - 'a'];
        if (!next) next = new TrieNode();
        node = next;  // Here next != node->next
      }
      node->is_end = true;
    }

    return dfs(s, 0);
  }
  bool dfs(const string &s, int cur) {  // search for s[cur:]
    if (cur == s.size()) return true;

    TrieNode *node = root;
    for (int i = cur; i < s.size(); ++i) {
      char ch = s[i];
      if (!node->next[ch - 'a']) break;

      node = node->next[ch - 'a'];
      if (node->is_end) {
        if (!visited[i + 1] && dfs(s, i + 1)) return true;
      }
    }
    visited[cur] = true;
    return false;
  }
};
