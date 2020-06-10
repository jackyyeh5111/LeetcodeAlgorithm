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
#include <stack>
class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> result;
        if (!root) return result;

        stack<Node*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            Node* node = node_stack.top();
            node_stack.pop();
            result.push_back(node->val);
            for (int i=node->children.size()-1; i>=0; --i)
                node_stack.push(node->children[i]);
        }

        return result;
    }
};
