/***** Third Visit *****/
/*
    TRIE+backtracking
*/
class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string val="";
        TrieNode ()
        {
            for (int i=0; i<26; ++i) child[i]=0;
            val="";
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieNode *root=new TrieNode();
        for (string word:words) {
            TrieNode *cur=root;
            for (char c:word) {
                if (!cur->child[c-'a'])
                    cur->child[c-'a']=new TrieNode();
                cur=cur->child[c-'a'];
            }
            cur->val=word;
        }

        vector<string> ans;
        int m=board.size(), n=board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                dfs(board,ans,root,i,j,m,n);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &board, vector<string> &ans, TrieNode *root,
             int i, int j, int m, int n)
    {
        if (i<0||i>=m||j<0||j>=n||board[i][j]=='0') return;
        if (!root->child[board[i][j]-'a']) return;
        root=root->child[board[i][j]-'a'];
        if (root->val!="") {
            ans.push_back(root->val);
            root->val="";
        }
        char tmp=board[i][j];
        board[i][j]='0';
        dfs(board,ans,root,i+1,j,m,n);
        dfs(board,ans,root,i-1,j,m,n);
        dfs(board,ans,root,i,j+1,m,n);
        dfs(board,ans,root,i,j-1,m,n);
        board[i][j]=tmp;
    }
};

/***** Second Visit *****/
class Solution {
public:

    struct TrieNode {
        TrieNode *children[26];
        string word;
        TrieNode()
        {
            for (int i=0; i<26; ++i) children[i]=0;
            word="";
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        /*
            Backtracking all word iteratively will make TLE.
            Use TRIE to track all words at the same time.
        */

        // build Trie
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *cur=root;
            for (char c:word) {
                if (!cur->children[c-'a'])
                    cur->children[c-'a']=new TrieNode();
                cur=cur->children[c-'a'];
            }
            cur->word=word;
        }

        vector<string> ans;
        int rows=board.size(); int cols=board[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                dfs(board,i,j,rows,cols,root,ans);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, int row, int col, int rows, int cols, TrieNode *node, vector<string> &ans)
    {
        if (row<0||row>=rows||col<0||col>=cols||board[row][col]=='.') return;
        node=node->children[board[row][col]-'a'];
        if (!node) return;
        if (node->word!="") { ans.push_back(node->word); node->word=""; }
        char tmp=board[row][col];
        board[row][col]='.';
        dfs(board,row+1,col,rows,cols,node,ans);
        dfs(board,row-1,col,rows,cols,node,ans);
        dfs(board,row,col+1,rows,cols,node,ans);
        dfs(board,row,col-1,rows,cols,node,ans);
        board[row][col]=tmp;
    }
};

/***** First Visit *****/
/************* Recursive TLE ****************/
/*
    T:O(numWord * 4^wordLength)
*/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        /*
            find each word in board. Notice large test case.
            Find out the first char in the board and start back tracking.
        */
        unordered_map<char,vector<vector<int>>> m;
        for (int row=0; row<board.size(); ++row) {
            for (int col=0; col<board[0].size(); ++col) {
                if (m.find(board[row][col])==m.end())
                    m[board[row][col]]=vector<vector<int>>{};
                m[board[row][col]].push_back(vector<int>{row,col});
            }
        }
        vector<string> ans;
        for (string word:words){
            vector<vector<int>> starts = m[word[0]];
            for(vector<int> start:starts){
                if(findWord(board,word,start[0],start[1],0)){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }

    bool findWord(vector<vector<char>>& board, string word, int row, int col, int i)
    {
        if (i==word.length()) return true;
        if (row<0||row>board.size()-1||col<0||col>board[0].size()-1) return false;
        if (board[row][col]=='1') return false;
        if (board[row][col]!=word[i]) return false;
        char tmp=board[row][col]; board[row][col]='1';
        bool found=false;
        if(findWord(board,word,row-1,col,i+1) ||
           findWord(board,word,row+1,col,i+1) ||
           findWord(board,word,row,col+1,i+1) ||
           findWord(board,word,row,col-1,i+1))
            found=true;
        board[row][col]=tmp;
        return found;
    }
};

/************* Trie ****************/
/*
    Worst case: T:O(m*n*4^maxWorLength)
    But we can consider all words simultaneously, thus we can apply early stop
    for MULTIPLE words.
*/
class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word; // <------ KEY!!! we could do early stop here.
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return; // EARLY STOP
        p = p->children[c - 'a'];
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};
