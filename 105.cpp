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
class Solution {
public:
    vector<int> pos_pre, pos_in;

    /*     
        pre: C L L L R R R
         in: L L L C R R R 
             Ll Lc Lr
     */
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        int N = preorder.size();
        if (N == 0) return nullptr;
        if (N == 1) return new TreeNode(preorder[0]);

        // mapping position
        mapPosition(preorder, inorder, pos_in);
        mapPosition(inorder, preorder, pos_pre);
        
        /* 
             pre: C L L L R R R
              in: L L L C R R R 
                  Ll Lc Lr

            pre: C L L
             in: L L C

            pre: C R R
             in: C R R

            pre: C
             in: C

            if (N == 1)
            if (N != 1 && C == N-1)
            if (N != 1 && C == 0)

             pre: 1 4 3 2
              in: 2 1 3 4
         pos_pre: 1 3 2 0
          pos_in: 3 0 2 1
         */
        vector<int> l_pre, r_pre, l_in, r_in;
        TreeNode *root = new TreeNode(preorder[0]);
        int C_inorder_pos = pos_pre[0];
        bool has_left_tree = true, has_right_tree = true;
        if (C_inorder_pos == N - 1) 
            has_right_tree = false;
        if (C_inorder_pos == 0)
            has_left_tree = false;

        if (has_left_tree) {
            l_pre.assign(preorder.begin()+1, preorder.begin() + pos_in[C_inorder_pos - 1] + 1);
            l_in.assign(inorder.begin(), inorder.begin() + C_inorder_pos);
            root->left = buildTree(l_pre, l_in);
        }
        if (has_right_tree) {
            r_pre.assign(preorder.begin()+ pos_in[C_inorder_pos + 1], preorder.end());
            r_in.assign(inorder.begin() + C_inorder_pos + 1, inorder.end());
            root->right = buildTree(r_pre, r_in);
        }

        return root;
    }

    void mapPosition(const vector<int>& vec1, const vector<int>& vec2, vector<int> &pos) {
        int N = vec1.size();
        unordered_map<int, int> um;
        for (int i = 0; i < N; ++i)
            um[vec1[i]] = i;
        pos.resize(N);
        for (int i = 0; i < N; ++i)
            pos[i] = um[vec2[i]];
    }

};

/* 
    pre: 1 4 3 2
     in: 2 1 3 4
pos_pre: 1 3 2 0
 pos_in: 3 0 2 1

    pre: C L L L R R R
     in: L L L C R R R 
         Ll Lc Lr

        1           1
       2 3.        2
                  3
 */

