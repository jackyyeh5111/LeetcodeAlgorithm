/***** Second Visit *****/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<pair<TreeNode*,bool>> s;
        vector<int> ans;
        if (root) s.push(make_pair(root,false));
        while (!s.empty()) {
            auto p=s.top(); s.pop();
            if (p.second) ans.push_back(p.first->val);
            else {
                p.second=true;
                s.push(p);
                if (p.first->right)
                    s.push(make_pair(p.first->right,false));
                if (p.first->left)
                    s.push(make_pair(p.first->left,false));
            }
        }
        return ans;
    }
};

/***** First Visit *****/
/************** Use bool flag **************/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        /*
            iterative needs a stack.
            postOrder: LRN, thus we can push into stack in REVERSE order.
            Here root node is visited after L/R, thus we can add a flag to
            identify where it's LR is visited.
            -----------
            Could we do it without bool flag? YES!!!
            If there's a node without children, visit it.
            else push its child and SET ITS CHILD LINK as 0.
        */
        vector<int> ans;
        stack<pair<TreeNode*,bool>> s;
        if (root) s.push(make_pair(root,false));
        while(!s.empty()) {
            auto node=s.top();
            if (node.second) {
                ans.push_back(node.first->val);
                s.pop();
            }
            else {
                node.second=true;
                s.pop(); s.push(node);
                if(node.first->right)
                    s.push(make_pair(node.first->right,false)); //push R first
                if(node.first->left)
                    s.push(make_pair(node.first->left,false)); //then push L
            }
        }
        return ans;
    }
};

 /************** Save bool flag, just modify the tree! **************/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            if (!node->left && !node->right) {
                result.push_back(node->val);
                node_stack.pop();
            }
            if (node->right) {
                node_stack.push(node->right);
                node->right = NULL;
            }
            if (node->left) {
                node_stack.push(node->left);
                node->left = NULL;
            }
        }
        return result;
    }
};

 /************** Start from left most node and do LRN **************/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;
        TreeNode* predecessar=nullptr;
        while (root || !node_stack.empty()) {
            if (root) {
                node_stack.push(root);
                root = root->left;
            }
            else {
                TreeNode* node = node_stack.top();
                if (node->right && node->right != predecessar) {
                    root = node->right;
                }
                else {
                    result.push_back(node->val);
                    node_stack.pop();
                    predecessar = node;
                }

            }
        }
        return result;
    }
};
