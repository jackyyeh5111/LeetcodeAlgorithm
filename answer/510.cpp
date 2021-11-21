class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node=node->right;
            while(node->left) node=node->left;
            return node;
        }
        else {
            while(node->parent&&node->parent->right==node)
                node=node->parent;
            node=node->parent;
            return node;
        }
    }
};
