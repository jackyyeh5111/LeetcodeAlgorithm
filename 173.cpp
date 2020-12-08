/***** Second Visit *****/
/*
    constraint: T:O(1)/S:O(logn) in average of next() & hasNext()
    Directly use iteratively inorder traversal
    The max size of stack would be O(logn), i.e. the height of the tree.
*/
class BSTIterator {
public:
    stack<pair<TreeNode*,bool>> s;
    BSTIterator(TreeNode* root) {
        if (root)
            s.push(make_pair(root,false));
    }

    /** @return the next smallest number */
    int next() {
        while (!s.empty()) {
            auto t=s.top(); s.pop();
            if (t.second) return t.first->val;
            else {
                if (t.first->right)
                    s.push(make_pair(t.first->right,false));
                s.push(make_pair(t.first,true));
                if (t.first->left)
                    s.push(make_pair(t.first->left,false));
            }
        }
        return -1; // invalid next
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/***** First Visit *****/
class BSTIterator {
public:
    vector<int> table;
    int index=0;
    BSTIterator(TreeNode* root) {
        TreeNode *cur=root, *pred=0;
        while (cur) {
            if (!cur->left) {
                table.push_back(cur->val);
                cur=cur->right;
            }
            else {
                pred=cur->left;
                while(pred->right&&pred->right!=cur)
                    pred=pred->right;
                if (pred->right==cur) {
                    table.push_back(cur->val);
                    cur=cur->right;
                }
                else {
                    pred->right=cur;
                    cur=cur->left;
                }
            }
        }
    }

    /** @return the next smallest number */
    int next() {
        return table[index++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<table.size();
    }
};
