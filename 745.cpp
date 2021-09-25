class WordFilter {
public:
    struct TrieNode {
        int val=-1;
        TrieNode *children[256]={0};
        TrieNode(){}
    };
    TrieNode *root=0;
    WordFilter(vector<string>& words) {
        int cnt=0;
        root=new TrieNode();
        for (auto word:words) {
            word="#"+word;
            for (int i=0; i<word.length(); ++i) {
                string tmp=word.substr(word.length()-i)+word;
                // cout<<tmp<<endl;
                TrieNode *cur=root;
                for (char &c:tmp) {
                    if (!cur->children[c]) cur->children[c]=new TrieNode();
                    cur=cur->children[c];
                }
                cur->val=cnt;
            }
            cnt++;
        }
    }

    int f(string prefix, string suffix) {
        string q=suffix+"#"+prefix;
        TrieNode *cur=root;
        for (char c:q) {
            if (!cur->children[c]) return -1;
            cur=cur->children[c];
        }
        return RNL(cur);
    }

    int RNL(TrieNode *node)
    {
        if (!node) return -1;
        else if (node->val!=-1) return node->val;
        int ret=-1;
        for (int i=255; i>=0; --i) {
            ret=max(ret,RNL(node->children[i]));
        }
        return ret;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
