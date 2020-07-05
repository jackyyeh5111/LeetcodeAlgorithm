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
            This time the tree is not complete binary tree.
            Constant space means we need to utilize 'next' ptr to traverse.
            Here Im going to try iterative approach.
            for each node:
                if !left&&!right continue
                if left&&right left->next=right
                link cross node next ptr with prev.
            after level traverse, move head to next level.
            T:O(n), S:O(1)
            -------------- update --------------
            the head of next level is actually the first prev. which is not null.
        */
        Node *prev=0, *head=root, *cur=0;
        while(head){
            cur=head; prev=0;
            while(cur) {
                if(!cur->left&&!cur->right) {cur=cur->next;}
                else if (cur->left&&cur->right) {
                    cur->left->next=cur->right;
                    if(prev) prev->next=cur->left;
                    prev=cur->right;
                    cur=cur->next;
                }
                else if (cur->left) {
                    if(prev) prev->next=cur->left;
                    prev=cur->left;
                    cur=cur->next;
                }
                else {
                    if(prev) prev->next=cur->right;
                    prev=cur->right;
                    cur=cur->next;
                }
            }
            while(head&&!head->left&&!head->right) head=head->next;
            if(head&&head->left) head=head->left;
            else if(head&&head->right) head=head->right;
        }
        return root;
    }
};
