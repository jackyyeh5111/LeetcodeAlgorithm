/*
    Maintain a running counter
    Need:
    vector<int> ans
    cur_val, cur_count
    max_count
    Each time we meet altered incoming count, check if its feasible for our ans.
    T:O(n)/S:O(n)
    -----
    If we'd like to reduce to S:O(1), apply morris-traversal
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root)
    {
        int *cur_val=0;
        int cur_count=0,max_count=0;
        vector<int> ans;
        inorder(root,&cur_val,cur_count,max_count,ans);
        if (cur_val&&cur_count>max_count) ans={*cur_val};
        else if (cur_val&&cur_count==max_count) ans.push_back(*cur_val);
        return ans;
    }

    void inorder(TreeNode *root, int **cur_val, int &cur_count, int &max_count, vector<int> &ans)
    {
        if (!root) return;
        inorder(root->left,cur_val,cur_count,max_count,ans);
        if (*cur_val==0) {*cur_val=&(root->val); cur_count=1;}
        else if (**cur_val==root->val) cur_count++;
        else if (cur_count>max_count) {
            max_count=cur_count;
            ans={**cur_val};
            cur_count=1;
            **cur_val=root->val;
        }
        else if (cur_count==max_count) {
            ans.push_back(**cur_val);
            **cur_val=root->val;
            cur_count=1;
        }
        else {
            cur_count=1;
            **cur_val=root->val;
        }
        inorder(root->right,cur_val,cur_count,max_count,ans);
    }
};
