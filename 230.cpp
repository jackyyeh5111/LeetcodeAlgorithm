/***** Fourth Visit *****/

class Node {
public:
    int val,cnt;
    Node *left,*right;
    Node(int val)
    {
        this->val=val;
        cnt=1;
        left=0,right=0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        Node *head=copy(root);
        return find(head,k);
    }

    Node *copy(TreeNode *root)
    {
        if (!root) return 0;
        Node *n=new Node(root->val);
        n->left=copy(root->left);
        n->right=copy(root->right);
        if (n->left) n->cnt+=n->left->cnt;
        if (n->right) n->cnt+=n->right->cnt;
        return n;
    }

    int find(Node *root, int k)
    {
        if (root->left) {
            if (root->left->cnt>=k) return find(root->left,k);
            else if (root->left->cnt==k-1) return root->val;
            return find(root->right,k-root->left->cnt-1);
        }
        else if (k==1) return root->val;
        else return find(root->right,k-1);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }

    int inorder(TreeNode *root, int &k)
    {
        if (!root) return INT_MIN;
        int ret=INT_MIN;
        ret=inorder(root->left,k);
        if (ret!=INT_MIN) return ret;
        if (k--==1) return root->val;
        return inorder(root->right,k);
    }
};

/***** Third Visit *****/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return help(root,k);
    }

    int help(TreeNode* root, int &k)
    {
        if (!root) return INT_MIN;
        int left=help(root->left,k);
        if (left!=INT_MIN) return left;
        k--;
        if (k==0) return root->val;
        return help(root->right,k);
    }
};

/***** Second Visit *****/
/*
    search kth smallest on BST
    inorder traversal T:O(n)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<pair<TreeNode*,bool>> s;
        if (root) s.push({root,false});
        while (!s.empty()) {
            auto p=s.top(); s.pop();
            if (p.second) {
                k--;
                if (k==0) return p.first->val;
            }
            else {
                if (p.first->right) s.push({p.first->right,false});
                s.push({p.first,true});
                if (p.first->left) s.push({p.first->left,false});
            }
        }
        return -1;
    }
};
// Follow Up: what if we can modify data structure?
/*
    Add a node  counter, which could help tracing kth smallest num in O(h)
    insert/delete: T:O(h) to delete & update counters.
    find  kth:O(h)
*/
class Node {
public:
    int val, size;
    Node *left, *right;
    Node(int v) : val(v), size(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        Node* node = addSize(root);
        return find(node, k);
    }
private:
    Node* addSize(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        Node* node = new Node(root -> val);
        node -> left = addSize(root -> left);
        node -> right = addSize(root -> right);
        if (node -> left) {
            node -> size += node -> left -> size;
        }
        if (node -> right) {
            node -> size += node -> right -> size;
        }
        return node;
    }

    int find(Node* node, int k) {
        if (node -> left) {
            if (node -> left -> size >= k) {
                return find(node -> left, k);
            }
            if (node -> left -> size == k - 1) {
                return node -> val;
            }
            return find(node -> right, k - node -> left -> size - 1);
        }
        if (k == 1) {
            return node -> val;
        }
        return find(node -> right, k - 1);
    }
};

/***** First Visit *****/
/*
    binary search tree: inorder traversal brings sorted order.
    recursive/iterative
    ---------
    Follow up:
    What if the BST is modified (insert/delete operations) often and you need
    to find the kth smallest frequently

    Use kind of B+ tree, LRU cache. A linkedlist and a hashmap.
      5
     2 9
     >3    while insert 3, use its last ptr 2 to find its sorted order in
           linked list. Then add 3 right after it.
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<pair<TreeNode*,bool>> s;
        if (root) s.push(make_pair(root,false));
        while(!s.empty()) {
            auto item=s.top(); s.pop();
            if (item.second) {
                k--;
                if (k==0) return item.first->val;
            }
            else {
                TreeNode *node=item.first;
                if (node->right) s.push(make_pair(node->right,false));
                s.push(make_pair(node,true));
                if (node->left) s.push(make_pair(node->left,false));
            }
        }
        return -1;
    }
};
