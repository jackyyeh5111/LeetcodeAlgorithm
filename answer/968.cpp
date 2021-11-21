/*
             a
        b          c
    d       e  f       g
         h
    for each node, return min cameras we need to monitor all subnodes by <set camera, not set camera>
    use postDFS to traverse from bottom-up
    T:O(n)/S:O(n)

            a
    {0,1001} {0,1001}

     a
    b {0,1001}
    -----
    1. set camera -> all the subnodes are covered.
    2. not set camera -> all the subnodes are covered, includes current node.
    3. not set camera -> all the subnodes are covered, excludes current node.
*/
class Solution {
public:
    int minCameraCover(TreeNode* root)
    {
        auto ret=postDFS(root);
        return min(ret[0],ret[1]);
    }

    vector<int> postDFS(TreeNode *root)
    {
        if (!root) return {1001,0,0};
        auto left=postDFS(root->left);
        auto right=postDFS(root->right);
        int ret1=min(left[0],min(left[1],left[2]))+min(right[0],min(right[1],right[2]))+1;
        int ret2=min(left[0]+min(right[1],right[0]),right[0]+min(left[1],left[0]));
        int ret3=left[1]+right[1];
        return {ret1,ret2,ret3};
    }
};
