#include "../utils.hpp"

/*
["cat", "dig", "dog", "dogs"]
Each node represents a character or a part of a string. The root node represents
starting point of prefix tree, represneting an empty string For each end of a
string, we can add a flag "end" to the node.

                    [ root ]
                   /         \
               [d]  (2)       [c] (1)
             /      \           \
          [o]       [i] (1)      [a] (1)
            \          \            \
     end -> [g]        [g] (1)     [t] (1)
              \
       end -> [s]
 */
class TrieNode {
 public:
  int num_branch = 26;
  vector<TrieNode *> next;
  int count = 0;
  TrieNode() { next.resize(num_branch, nullptr); }
};

class SuffixTrie {
 public:
  TrieNode *root;
  SuffixTrie() { this->root = new TrieNode(); }

  void insert(string word) {
    TrieNode *ptr = this->root;
    for (int i = word.size() - 1; i >= 0; i--) {
      char ch = word[i];
      int id = ch - 'a';
      if (!ptr->next[id]) ptr->next[id] = new TrieNode();
      ptr = ptr->next[id];
      ptr->count++;
    }
  }

  int endsWith(string suffix) {
    TrieNode *ptr = this->root;
    for (int i = suffix.size() - 1; i >= 0; i--) {
      char ch = suffix[i];
      int id = ch - 'a';
      if (!ptr->next[id]) return 0;
      ptr = ptr->next[id];
    }
    return ptr->count;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
 public:
  int output(vector<string> words) {
    int count = 0;

    unordered_map<string, int> word_to_cnt;

    // check in reverse order for prefix
    SuffixTrie *re_trie = new SuffixTrie();
    cout << "Prefix: ";
    for (int i = words.size() - 1; i >= 0; i--) {
      string word = words[i];
      word_to_cnt[word]++;

      count += re_trie->endsWith(word);
      if (re_trie->endsWith(word)) {
        cout << words[i] << ' ';
      }
      re_trie->insert(word);
    }
    cout << '\n';

    // check in order for suffix
    cout << "Suffix: ";
    re_trie = new SuffixTrie();
    for (int i = 0; i < words.size(); i++) {
      string word = words[i];

      count += re_trie->endsWith(word);
      if (re_trie->endsWith(word)) {
        cout << words[i] << ' ';
      }
      re_trie->insert(word);
    }
    cout << '\n';

    // same words serve as prefix and suffix of itself, we only have to count it once.
    for (auto it = word_to_cnt.begin(); it != word_to_cnt.end(); it++) {
        if (it->second > 1) {
            int num_repeat = 1;
            for (int i = 1; i <= it->second; i++)
                num_repeat *= i;
            count -= num_repeat / 2;
        }
    }

    return count;
  }
};

int main(int argc, char **argv) {
  vector<string> words{"back", "backdoor", "comeback", "come",
                       "door", "test",     "test"};
  print(words);
  Solution sol;
  int ans = sol.output(words);
  cout << "ans: " << ans << '\n';

  words = {"cba", "a", "a", "b", "ba", "ca"};
  print(words);
  ans = sol.output(words);
  cout << "ans: " << ans << '\n';

  return 0;
}