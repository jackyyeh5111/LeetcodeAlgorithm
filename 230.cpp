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
