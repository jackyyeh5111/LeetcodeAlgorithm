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
        vector<int> result;
        if (!root) return result;
        traverse(root, result);
        return result;
    }

    void traverse(Node* root, vector<int>& result)
    {
        if (root->children.empty()) {
            result.push_back(root->val);
            return;
        }
        result.push_back(root->val);
        for (int i=0; i<root->children.size(); ++i)
            traverse(root->children[i], result);
    }
};
