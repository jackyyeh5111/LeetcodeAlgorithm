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
#include <vector>
class Solution {
public:
    vector<int> postorder(Node* root) {
        std::vector<int> result;
        if (!root)
            return result;

        traverse(root, result);
        return result;
    }

    void traverse(Node* node, std::vector<int>& result)
    {
        if (node->children.size() == 0){
            result.push_back(node->val);
            return;
        }

        for (int i=0; i < node->children.size(); ++i)
            traverse(node->children[i], result);
        result.push_back(node->val);
    }
};
