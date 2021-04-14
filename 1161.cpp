class Solution {
public:
    int maxLevelSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        if (root) q.push(root);
        int cmax=INT_MIN, cmaxidx=0, cidx=1;
        while (!q.empty()) {
            int k=q.size(), csum=0;
            for (int i=0; i<k; ++i) {
                auto node=q.front(); q.pop();
                csum+=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (csum>cmax) {cmax=csum; cmaxidx=cidx;}
            cidx++;
        }
        return cmaxidx;
    }
};
