/*
    s = abcd
    dict = ["ab", "abc", "cd"]

           r
        a     c
      b         d
        c
 */
class Solution2 {
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
    visited.resize(s.size() + 1);

    // initialze TrieNode
    root = new TrieNode();
    for (auto word : wordDict) {
      TrieNode *node = root;
      for (char ch : word) {
        if (!node->next[ch - 'a']) node->next[ch - 'a'] = new TrieNode();
        node = node->next[ch - 'a'];
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
        node = next; // Here next != node->next
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
