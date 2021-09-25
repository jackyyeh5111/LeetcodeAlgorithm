/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> ans;
        stack<Node*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            auto t=s.top(); s.pop();
            ans.push_back(t->val);
            int n=t->children.size();
            for (int i=n-1; i>=0; --i) {
                s.push(t->children[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }

    void dfs(Node *root, vector<int> &ans)
    {
        if (!root) return;
        ans.push_back(root->val);
        for (Node *child:root->children)
            dfs(child,ans);
    }
};
