/***** Third Visit *****/
class Trie {
public:
    /** Initialize your data structure here. */
    struct Node {
        Node *children[26]={0};
        string val="";
        Node(string val="") {this->val=val;}
    };

    Node *root=0;
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur=root;
        for (char c:word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a']=new Node();
            cur=cur->children[c-'a'];
        }
        cur->val=word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur=root;
        for (char c:word) {
            if (!cur->children[c-'a'])
                return false;
            cur=cur->children[c-'a'];
        }
        return cur->val!="";
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur=root;
        for (char c:prefix) {
            if (!cur->children[c-'a'])
                return false;
            cur=cur->children[c-'a'];
        }
        return true;
    }
};

/***** Second Visit *****/
class Trie {
public:
    /** Initialize your data structure here. */
    struct Node  {
        Node *child[26];
        string val="";
        Node()
        {
            val="";
            for(auto &n:child) n=0;
        }

    };

    Node *root=0;
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur=root;
        for (char c:word) {
            if (!cur->child[c-'a'])
                cur->child[c-'a']=new Node();
            cur=cur->child[c-'a'];
        }
        cur->val=word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur=root;
        for (char c:word) {
            if (!cur->child[c-'a']) return false;
            cur=cur->child[c-'a'];
        }
        return cur->val!="";
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur=root;
        for (char c:prefix) {
            if (!cur->child[c-'a']) return false;
            cur=cur->child[c-'a'];
        }
        return true;
    }
};

/***** First Visit *****/
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
