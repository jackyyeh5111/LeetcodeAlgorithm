class Trie {
public:
    struct TrieNode {
        string val;
        TrieNode *child[26];
        TrieNode():val(""){
            for (int i=0; i<26; ++i) {
                child[i]=0;
            }
        }
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur=root;
        for (char c:word) {
            if (!cur->child[c-'a'])
                cur->child[c-'a'] = new TrieNode();
            cur=cur->child[c-'a'];
        }
        cur->val=word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur=root;
        for (char c:word) {
            if (!cur->child[c-'a']) return false;
            cur=cur->child[c-'a'];
        }
        return cur->val!="";
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur=root;
        for (char c:prefix) {
            if (!cur->child[c-'a']) return false;
            cur=cur->child[c-'a'];
        }
        if (cur->val!="") return true;
        for (int i=0; i<26; ++i) {
            if (cur->child[i]) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
