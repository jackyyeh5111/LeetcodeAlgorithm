/*
    data strucure: set/map
    separately handling exact/capitalization/vowel cases.
    T:O(nk)/S:O(nk)
    -----
    data structure: TRIE
    capitalization: handle lower case only. T:O(k)
    vowel error: backtracking on same length words. T:O(5^k)
    space: T:O(n)
    k: max word length, n: # of words
*/

// set/map/map
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_set<string> exact(wordlist.begin(),wordlist.end());
        unordered_map<string,string> cap,vowel;
        for (string &word:wordlist) {
            if (cap.count(tocap(word))==0)
                cap[tocap(word)]=word;
            if (vowel.count(tovowel(word))==0)
                vowel[tovowel(word)]=word;
        }

        for (string &q:queries) {
            if (exact.count(q)) continue;
            else if (cap.count(tocap(q))) q=cap[tocap(q)];
            else if (vowel.count(tovowel(q))) q=vowel[tovowel(q)];
            else q="";
        }
        return queries;
    }

    string tocap(string s)
    {
        string ret=s;
        for (char &c:ret) c=tolower(c);
        return ret;
    }

    string tovowel(string s)
    {
        string ret=s;
        for (char &c:ret) {
            c=tolower(c);
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                c='#';
        }
        return ret;
    }
};

// TrieNode
class Solution {
public:
    struct TrieNode {
        vector<pair<string,int>> word;
        TrieNode *children[26]={0};
        TrieNode(){}
    };

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        // Consntruct Trie Data Structure.
        TrieNode *root=new TrieNode();
        int p=0;
        for (string &word:wordlist) {
            TrieNode *cur=root;
            for (char &c:word) {
                if (!cur->children[tolower(c)-'a'])
                    cur->children[tolower(c)-'a']=new TrieNode();
                cur=cur->children[tolower(c)-'a'];
            }
            cur->word.push_back({word,p++});
        }

        char vowel[5]={'a','e','i','o','u'};
        unordered_set<string> wordset(wordlist.begin(),wordlist.end());
        vector<string> ans;
        for (string &q:queries) {
            if (wordset.count(q)) ans.push_back(q);
            else {
                bool capOnly=true; ans.push_back(dfs(root,q,0,vowel,capOnly).first);
            }
        }
        return ans;
    }

    pair<string,int> dfs(TrieNode *root, string word, int idx, char* vowel, bool &capOnly)
    {
        pair<string,int> ret={"",INT_MAX};
        if (idx==word.length()) return root->word.empty()?ret:root->word[0];
        char c=word[idx];
        if (root->children[tolower(c)-'a']) {
            ret=dfs(root->children[tolower(c)-'a'],word,idx+1,vowel,capOnly);
            if (capOnly&&ret.first!="") ret.second=-1;
        }
        if (tolower(c)=='a'||tolower(c)=='e'||tolower(c)=='i'||tolower(c)=='o'||tolower(c)=='u') {
            for (int t=0; t<5; ++t) {
                if (vowel[t]==c) continue;
                else if (!root->children[vowel[t]-'a']) continue;
                capOnly=false;
                auto k=dfs(root->children[vowel[t]-'a'],word,idx+1,vowel,capOnly);
                if (k.second<ret.second) ret=k;
            }
        }
        return ret;
    }
};
