class WordDictionary {
public:
    /** Initialize your data structure here. */
    /*
        Use a TRIE for string handling.
        S:O(26*m) -> S:O(m), m: max length of word
    */
    struct TrieNode {
        TrieNode *children[26];
        bool exist;
        TrieNode()
        {
            for (int i=0; i<26; ++i) children[i]=0;
            exist=false;
        }
    };

    TrieNode *root=0;
    WordDictionary() {
        root=new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        // T:O(m)
        TrieNode *cur=root;
        for (char c:word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a']=new TrieNode();
            cur=cur->children[c-'a'];
        }
        cur->exist=true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }

    bool search(string &word, TrieNode *cur) {
        int size=word.length();
        for (int i=0; i<size; ++i) {
            // cout<<word<<","<<i<<endl;
            if (word[i]=='.') {
                bool found=false;
                string subword=word.substr(i+1);
                for (int c=0; c<26; ++c) {
                    if (!cur->children[c]) continue;
                    found|=search(subword,cur->children[c]);
                }
                return found;
            }
            else if (!cur->children[word[i]-'a']) return false;
            else cur=cur->children[word[i]-'a'];
        }
        return cur->exist;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
