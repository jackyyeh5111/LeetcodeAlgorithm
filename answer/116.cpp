/***** Fourth Visit *****/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return 0;
        int k=1;
        Node *head=root;
        while (head->left) {
            Node *prev=0, *cur=head;
            for (int i=0; i<k; ++i) {
                cur->left->next=cur->right;
                if (prev) prev->next=cur->left;
                prev=cur->right;
                cur=cur->next;
            }
            head=head->left;
            k*=2;
        }
        return root;
    }
};

/***** Third Visit *****/
/*
    constraint: constant space complexity
    -----
    level order traversal
    T:O(n)/S:O(n)
    -----
    Due to complete binary tree, just calculate the nums of nodes in next leve.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    Node* connect(Node* root)
    {
        int k=1; Node *head=root;
        while (head) {
            Node *nextLevel=head->left;
            Node *header=new Node(), *tail=header;
            for (int i=0; i<k; ++i) {
                if (head->left) {
                    tail->next=head->left;
                    tail=tail->next;
                }
                if (head->right) {
                    tail->next=head->right;
                    tail=tail->next;
                }
                head=head->next;
            }
            tail->next=0;
            delete header;
            head=nextLevel;
            k<<=1;
        }
        return root;
    }
};

/***** Second Visit *****/
/*
    level order traversal
    T:O(n)/S:O(n)
    -----
    postorder traversal
    LRN
    T:O(n)/S:O(n) but recursive is fine.
    -----
    According to the description, the tree is guarenteed as PERFECT binary tree
    T:O(n)/S:O(1)
*/
class Solution {
public:
    Node* connect(Node* root)
    {
        int depth=0;
        Node *head=root;
        while (head&&head->left) {
            int k=pow(2,depth);
            Node *prev=0, *cur=head;
            for (int i=0; i<k; ++i) {
                Node *left=cur->left;
                Node *right=cur->right;
                if (prev) prev->next=left;
                left->next=right;
                prev=right;
                cur=cur->next;
            }
            head=head->left;
            depth++;
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
