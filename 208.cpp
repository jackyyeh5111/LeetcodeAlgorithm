/* 
["cat", "dig", "dog", "dogs"]
Each node represents a character or a part of a string. The root node represents starting point of prefix tree, represneting an empty string
For each end of a string, we can add a flag "end" to the node.

                    [ root ]
                   /         \
               [d]            [c]
             /      \           \   
          [o]       [i]          [a]       
            \          \            \   
     end -> [g]        [g] <- end    [t]  <- end 
              \
       end -> [s]
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
class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *ptr = this->root;
        for (char ch : word) {
            int id = ch - 'a';
            if (!ptr->next[id])
                ptr->next[id] = new TrieNode();
            ptr = ptr->next[id];
        }
        ptr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode *ptr = this->root;
        for (char ch : word) {
            int id = ch - 'a';
            if (!ptr->next[id]) return false;
            ptr = ptr->next[id];
        }
        return ptr->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = this->root;
        for (char ch : prefix) {
            int id = ch - 'a';
            if (!ptr->next[id]) return false;
            ptr = ptr->next[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */