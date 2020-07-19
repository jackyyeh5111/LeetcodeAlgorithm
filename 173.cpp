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
