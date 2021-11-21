/***** Second Visit *****/
/*
    conducct postDFS as if depth > d return current node;
    else if depth==d create new nodes
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode *newR=new TreeNode(v);
            newR->left=root;
            return newR;
        }
        return postDFS(root,v,d,1,0);
    }

    TreeNode *postDFS(TreeNode* root, int v, int d, int curD, bool isLeft)
    {
        if (curD>d) return 0;
        else if (!root&&curD==d) return new TreeNode(v);
        else if (!root) return 0;

        TreeNode *left=postDFS(root->left,v,d, curD+1,true);
        TreeNode *right=postDFS(root->right,v,d, curD+1,false);
        if (d==curD) {
            TreeNode *node=new TreeNode(v);
            if (isLeft) node->left=root;
            else node->right=root;
            return node;
        }
        root->left=left;
        root->right=right;
        return root;
    }
};

/***** First Visit *****/
/*
    level order traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        queue<TreeNode*> q;
        TreeNode *header=new TreeNode();
        header->left=root;
        q.push(header);
        for (int i=0; i<d-1; ++i) {
            int k=q.size();
            for (int j=0; j<k; ++j) {
                TreeNode *node=q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        while (!q.empty()) {
            TreeNode *node=q.front(); q.pop();
            TreeNode *left=node->left, *right=node->right;
            node->left=new TreeNode(v);
            node->left->left=left;
            node->right=new TreeNode(v);
            node->right->right=right;
        }
        return header->left;
    }
};
