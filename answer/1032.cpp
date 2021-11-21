/*
    string comparison: TRIE!
    Conduct a vector/set of pointers to check
    T:O(mn)/S:O(m), m: # of word, n: max length of word
    worst case: T:O(26^n)/S:O(26^n)
    -----
    use an inverse string TRIE.
    then check latest queries to find the trienode which has value.
    construct T:O(mn)/S:O(mn)
    query T:O(k), k denotes the max length of word.
*/

/*************** Non-inverse TRIE (TLE) ***************/
class StreamChecker {
public:
    struct TrieNode {
        string val="";
        TrieNode* children[26];
        TrieNode(){
            for (int i=0; i<26; ++i) children[i]=0;
        }
    };

    unordered_set<TrieNode*> v;
    TrieNode *root=0;
    StreamChecker(vector<string>& words)
    {
        root=new TrieNode();
        for (auto word:words) {
            cout<<word<<endl;
            TrieNode *cur=root;
            for (char c:word) {
                if (!cur->children[c-'a']) cur->children[c-'a']=new TrieNode();
                cur=cur->children[c-'a'];
            }
            cur->val=word;
        }
    }

    bool query(char letter) {
        bool found=false;
        unordered_set<TrieNode*> tmp;
        for (auto it=v.begin();it!=v.end();it++) {
            if ((*it)->children[letter-'a']) {
                tmp.insert((*it)->children[letter-'a']);
                if ((*it)->children[letter-'a']->val!="") found=true;
            }
        }
        if (root->children[letter-'a']) {
            tmp.insert(root->children[letter-'a']);
            if (root->children[letter-'a']->val!="") found=true;
        }
        swap(tmp,v);
        return found;
    }
};

/*************** Inverse TRIE (AC) ***************/
 class StreamChecker {
 public:
     struct TrieNode {
         string val="";
         TrieNode* children[26];
         TrieNode(){
             for (int i=0; i<26; ++i) children[i]=0;
         }
     };

     vector<char> queries;
     TrieNode *root=0;
     int max_length=0;
     StreamChecker(vector<string>& words)
     {
         root=new TrieNode();
         for (auto word:words) {
             max_length=max(max_length,(int)word.length());
             reverse(word.begin(),word.end());
             TrieNode *cur=root;
             for (char c:word) {
                 if (!cur->children[c-'a']) cur->children[c-'a']=new TrieNode();
                 cur=cur->children[c-'a'];
             }
             cur->val=word;
         }
     }

     bool query(char letter)
     {
         queries.insert(queries.begin(),letter);
         if (queries.size()>max_length)
             queries.pop_back();
         TrieNode *cur=root;
         for (char q:queries) {
             if (cur->val!="") return true;
             else if (!cur->children[q-'a']) return false;
             cur=cur->children[q-'a'];
         }
         return cur->val!="";
     }
 };

 /**
  * Your StreamChecker object will be instantiated and called as such:
  * StreamChecker* obj = new StreamChecker(words);
  * bool param_1 = obj->query(letter);
  */
