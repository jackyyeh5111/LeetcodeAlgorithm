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
        std::stack<Node*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()){
            Node* node = node_stack.top();

            if (node->children.empty()){
                result.push_back(node->val);
                node_stack.pop();
            }
            else {
                std::cout << node->val << std::endl;
                for (int i=node->children.size()-1; i>=0; --i) {
                    node_stack.push(node->children[i]);
                }
                node->children.clear();
            }
        }
        return result;
    }

};
