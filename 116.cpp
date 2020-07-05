/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        /*
            constant space -> cannot use queue for level order traversal.
            Is there any other strategy to do such traversal?
            Here the tree is guaranteed to be a completely binary tree
            we can calculate # of nodes with iterative approach.
        */
        int depth=0;
        Node *cur=root, *head=root;
        while (head&&head->left) {
            int nums=pow(2,depth);
            cur=head;
            Node *prevRight=0;
            for (int num=0; num<nums; ++num){
                Node *left=cur->left;
                Node *right=cur->right;
                if (prevRight) prevRight->next=left;
                left->next=right; prevRight=right;
                cur=cur->next;
            }
            head=head->left;
            depth++;
        }
        return root;
    }
};
