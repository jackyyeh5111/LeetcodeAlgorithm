/***** Third Visit *****/
/*
    Level order traversal with Q
    T:O(n)/S:O(n)
    -----
    How to count next level's # of nodes? Actually we dont need to know.
    Just iterate through over the current level's nodes with next op.
    Meanwhile, record next level's head.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    Node* connect(Node* root)
    {
        Node *cur=root;
        while (cur) {
            Node *nextHead=0, *prev=0;
            while (cur) {
                if (cur->left) {
                    if (!nextHead) {nextHead=cur->left; prev=nextHead;}
                    else {prev->next=cur->left; prev=prev->next;}
                }
                if (cur->right) {
                    if (!nextHead) {nextHead=cur->right; prev=nextHead;}
                    else {prev->next=cur->right; prev=prev->next;}
                }
                cur=cur->next;
            }
            cur=nextHead;
        }
        return root;
    }
};

/***** Second Visit *****/
/*
    while loop with level order traversal, utilize 'next' ptr to traverse.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    Node* connect(Node* root)
    {
        Node *head=root, *cur=root;
        while (head) {
            cur=head; Node *prev=0;
            head=head->left;
            while (cur) {
                Node *left=cur->left;
                Node *right=cur->right;
                if (left||right) {
                    if (prev) prev->next=left?left:right;
                    if (left) left->next=right;
                    if(!prev) head=left?left:right;
                    prev=right?right:left;
                }
                cur=cur->next;
            }
        }
        return root;
    }
};

/***** First Visit *****/
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
