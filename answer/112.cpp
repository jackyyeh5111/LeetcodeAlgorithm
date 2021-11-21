 /***** Second Visit *****/
 // T:O(n)/S:O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (!root) return false;
        else if (!root->left&&!root->right) return root->val==sum;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);

    }
};

 /***** First Visit *****/
 /*
    Same to problem 111.
    Use preorder traversal and check sum while we reach leaf each time.
    T: O(n), O(logn)
    --------------------------
    We can also use queue to do level order traversal and check sum if we meet
    a node WITHOUT children. Each entry of Q must have a corresponding pathSum.
    T:O(n), S:O(logN)
    --------- Update ---------
    Use top down reduce sum approach with neat code.
    T:O(n), S:O(logn)
 */
// Top down reduce sum approach.
 class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (!root) return false;
        if (root->val==sum&&!root->left&&!root->right) return true;
        return hasPathSum(root->left,sum-root->val)||
               hasPathSum(root->right,sum-root->val);
    }
};


class Solution {
public:
    bool ans=false;
    bool hasPathSum(TreeNode* root, int sum)
    {
        checkSum(root,0,sum);
        return ans;
    }

    void checkSum(TreeNode* root, int sum, int target)
    {
        if(!root) return;
        sum+=root->val;
        if(!root->left&&!root->right&&sum==target) { ans=true; return; }
        checkSum(root->left,sum,target);
        checkSum(root->right,sum,target);
    }
};
