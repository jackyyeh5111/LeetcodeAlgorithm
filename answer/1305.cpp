/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/***** Stack without visited flag *****/
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        stack<TreeNode*> s1,s2;
        pushLeft(s1,root1); pushLeft(s2,root2);
        vector<int> ans;
        while (!s1.empty()||!s2.empty()) {
            stack<TreeNode*> &s=s1.empty()?s2:s2.empty()?s1:s1.top()->val<=s2.top()->val?s1:s2;
            TreeNode* node=s.top(); s.pop();
            ans.push_back(node->val);
            pushLeft(s,node->right);
        }
        return ans;
    }

    void pushLeft(stack<TreeNode*> &s, TreeNode* root)
    {
        TreeNode *node=root;
        while(node) {
            s.push(node);
            node=node->left;
        }
    }
};

/***** Stack with visited flag *****/
/*
    traverse each tree then sorting
    T:O((m+n)log(m+n))/S:O(m+n)
    -----
    insert right tree into left tree then traverse the integrated tree
    T:O(mn+m+n)/S:O(m+n)
    -----
    merge 2 sorted array
    traverse each tree then merge them
    T:O(m+n)/S:O(m+n), but 3 pass.
    -----
    try to merge within traverse them, 1 pass needed.
    T:O(m+n)/S:O(m+n)
*/
class Solution {
public:
    vector<int> ans;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        stack<pair<TreeNode*,bool>> s1,s2;
        if(root1) s1.push(make_pair(root1,false));
        if(root2) s2.push(make_pair(root2,false));
        while(!s1.empty()||!s2.empty()) {
            while(!s1.empty()&&!s1.top().second) {
                auto p1=s1.top(); s1.pop();
                if(p1.first->right) s1.push(make_pair(p1.first->right,false));
                s1.push(make_pair(p1.first,true));
                if(p1.first->left) s1.push(make_pair(p1.first->left,false));
            }
            while(!s2.empty()&&!s2.top().second) {
                auto p2=s2.top(); s2.pop();
                if(p2.first->right) s2.push(make_pair(p2.first->right,false));
                s2.push(make_pair(p2.first,true));
                if(p2.first->left) s2.push(make_pair(p2.first->left,false));
            }
            if (!s1.empty()&&s2.empty()) {
                ans.push_back(s1.top().first->val);
                s1.pop();
            }
            else if (s1.empty()&&!s2.empty()) {
                ans.push_back(s2.top().first->val);
                s2.pop();
            }
            else if (s1.top().first->val<s2.top().first->val) {
                ans.push_back(s1.top().first->val);
                s1.pop();
            }
            else if (s1.empty()||s1.top().first->val>s2.top().first->val) {
                ans.push_back(s2.top().first->val);
                s2.pop();
            }
            else {
                ans.push_back(s1.top().first->val);
                ans.push_back(s2.top().first->val);
                s1.pop(); s2.pop();
            }
        }
        return ans;
    }
};
