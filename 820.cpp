```
/*
    find if it is any of sub sequence.
    use trie and find all leaf nodes.
	T:O(n)/S:O(# of words), where n is the total num of chars.
*/
class Solution {
public:

    struct Node {
        string val;
        Node *children[26]={0};
        Node (string val=""){this->val=val;}
    };

    int minimumLengthEncoding(vector<string>& words) {
        Node *root=new Node();
        for (string word:words) {
            reverse(word.begin(),word.end());
            Node *cur=root;
            for (char c:word) {
                if (!cur->children[c-'a']) cur->children[c-'a']=new Node();
                cur=cur->children[c-'a'];
            }
            cur->val=word;
        }

        int ans=0;
        dfs(root,ans);
        return ans;
    }

    void dfs(Node *root, int &ans)
    {
        if (!root) return;
        bool isLeaf=true;
        for (int i=0; i<26; ++i) {
            if (!root->children[i]) continue;
            isLeaf=false;
            dfs(root->children[i],ans);
        }
        if (isLeaf) ans+=(root->val.length()+1);
    }
};
```
