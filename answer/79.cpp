/***** Third Visit *****/
/*
    backtracking:
    note that we have board with size at most. 200x200.
    T:O(mn*k)/S:O(1)
    -----
    string finding
    1. TRIE (V)
    2. KMP
    3. Treat it as array.
    -----
    We adopt TRIE here.
    T:O(mn*k)/S:O(k)
*/
class Solution {

    class TrieNode {
    public:
        TrieNode* children[255];
        string word;
        TrieNode()
        {
            for (auto &child:children) child=0;
            word="";
        }
    };
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        // build Trie
        TrieNode *root=new TrieNode();
        TrieNode *cur=root;
        for(char c:word) {
            if (!cur->children[c+128])
                cur->children[c+128]=new TrieNode();
            cur=cur->children[c+128];
        }
        cur->word=word;

        // check exist
        int m=board.size(), n=board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (help(board,i,j,root)) return true;
            }
        }
        return false;
    }

    bool help(vector<vector<char>>& board, int i, int j, TrieNode *node)
    {
        int m=board.size(), n=board[0].size();
        if (node&&node->word!="") return true;
        else if (i<0||i>=m||j<0||j>=n||!node) return false;
        node=node->children[board[i][j]+128];
        char tmp=board[i][j];
        board[i][j]='.';
        if ( help(board,i+1,j,node) ||
                  help(board,i,j+1,node) ||
                  help(board,i-1,j,node) ||
                  help(board,i,j-1,node) ) return true;
        else { board[i][j]=tmp; return false; }
    }
};

/***** Second Visit *****/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        /*
            find a SINGLE word -> backtracking
            find MULTIPLE words -> TRIE
        */
        int rows=board.size();
        int cols=board[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                bool found = dfs(board, i, j, rows, cols, 0, word);
                if (found) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, int rows, int cols, int s, string &word)
    {
        if (s==word.length()) return true;
        if (i<0||i>=rows||j<0||j>=cols) return false;
        if (board[i][j]!=word[s]) return false;
        char tmp = board[i][j];
        board[i][j]='1';
        bool found = dfs(board,i+1,j, rows, cols, s+1, word) ||
                     dfs(board,i-1,j, rows, cols, s+1, word) ||
                     dfs(board,i,j+1, rows, cols, s+1, word) ||
                     dfs(board,i,j-1, rows, cols, s+1, word);
        board[i][j]=tmp;
        return found;
    }
};

/***** First Visit *****/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        // we have constrain to avoid dummy input
        // if (word.length()==0) return true;
        // if (board.size()==0||board[0].size()==0) return false;
        // note that we should add flag that it has been traced.

        for (int row=0; row<board.size(); ++row) {
            for (int col=0; col<board[0].size(); ++col) {
                if (dfs(board,row,col,0,word)) return true;
            }
        }
        return false;

    }

    bool dfs(vector<vector<char>>& board, int i, int j, int idx, string& word)
    {
        if (idx==word.size()) return true;
        else if (i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        if (board[i][j]==word[idx]) {
            bool t=false,b=false,l=false,r=false;
            char record=board[i][j]; board[i][j]='1';
            b = dfs(board,i+1,j,idx+1,word);
            t = dfs(board,i-1,j,idx+1,word);
            r = dfs(board,i,j+1,idx+1,word);
            l = dfs(board,i,j-1,idx+1,word);
            bool found = t||b||l||r;
            if (found) return true;
            else{board[i][j]=record; return false;}
        }
        else return false;
    }
};
