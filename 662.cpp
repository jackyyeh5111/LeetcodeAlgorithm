/*
    Use level order traversal with index recording.
    However, this time we find the first node in each level, and consider it as
    starting index, i.e. 0. And all nodes after it need to subtract offset to
    avoid OVERFLOW.

    Basic idea is: At each level, reset the leftmost node id to zero (as well
                   as move the nodes right to this leftmost node):
    -------------------
    LRN to assign index then do calculate
    Use level order traversal (ignore nullptr) to record each level's index
    then we calculate max distance over each level.
    T:O(n),S:O(n)
    Cause INTEGER OVERFLOW. Since depth could be 2^31-1, index could be up to
    2^32 and leads OVERFLOW.
    -------------------
    use level order traversal, this time we cannot ignore nullptr
    T:O(2^n),S:O(n) <- TLE
    Even we add early stop with size check, parent check, still TLE.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<pair<TreeNode*,int>> q;
        if (root) q.push(make_pair(root,0));
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            auto front=q.front();
            int offset=front.second;
            int l=0, r=0;
            for (int i=0; i<size; ++i) {
                auto node=q.front(); q.pop();
                int val=node.second-offset;
                l=min(l,val);
                r=max(r,val);
                if(node.first->left) q.push(make_pair(node.first->left,val*2));
                if(node.first->right) q.push(make_pair(node.first->right,val*2+1));
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<long>> level_order;
    int widthOfBinaryTree(TreeNode* root)
    {
        help(root,0,0);
        long ans=0;
        for(auto level:level_order) ans=max(ans,level.back()-level[0]+1);
        return ans;
    }

    void help(TreeNode* root, int level, long index)
    {
        if (!root) return;
        if (level_order.size()<=level) level_order.push_back(vector<long>{});
        level_order[level].push_back(index);
        help(root->left,level+1,index*2);
        help(root->right,level+1,index*2+1);
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        int ans=0;
        if (root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            int l=-1,r=-1;
            for (int i=0; i<size; ++i) {
                TreeNode* node=q.front(); q.pop();
                if (node) {
                    if (l==-1) {l=i; r=i;}
                    else r=i;
                    q.push(node->left);
                    q.push(node->right);
                }
                else {q.push(0); q.push(0);}
            }
            if(l==-1) break;
            ans=max(r-l+1,ans);
        }
        return ans;
    }
};
