/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    [1,2,3,null,null,4,5]
    1     _
    2 3   1
    nn45  23

*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="[";
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            int n=q.size(); int clear=true;
            for (int i=0; i<n; ++i) {
                TreeNode *node=q.front(); q.pop();
                if (!node) {
                    ans+="null,";
                    q.push(0); q.push(0);
                    continue;
                }
                ans+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
                if (node->left||node->right) clear=false;
            }
            if (clear) break;
        }
        if (ans!="[") ans[ans.length()-1]=']';
        else ans+=']';
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=1, n=data.length();
        vector<TreeNode*> nodes;
        while(i<n-1) {
            string sub="";
            while(i<n-1&&data[i]!=',') sub+=data[i++];
            TreeNode *node=0;
            if (sub!="null") node=new TreeNode(stoi(sub));
            nodes.push_back(node);
            i++;
        }
        int size=nodes.size();
        for (int k=0; k<size/2; ++k) {
            if (!nodes[k]) continue;
            // cout<<nodes[k]->val<<endl;
            nodes[k]->left=nodes[2*k+1];
            if (size%2) nodes[k]->right=nodes[2*k+2];
        }
        return size>0?nodes[0]:0;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    [1,2,3,null,null,4,5]
    1     _
    2 3   1
    nn45  23

*/
class Codec {
public:

    void preorder(TreeNode* root, string &order)
    {
        if (!root) {order+="# "; return;}
        order+=to_string(root->val)+" ";
        preorder(root->left,order);
        preorder(root->right,order);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode="";
        preorder(root,encode);
        cout<<encode<<endl;
        return encode;
    }

    TreeNode* recons(vector<TreeNode*> &nodes, int &idx)
    {
        if (idx>=nodes.size()) return 0;
        TreeNode *node=nodes[idx++];
        if (!node) return node;
        node->left=recons(nodes,idx);
        node->right=recons(nodes,idx);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        int i=0,n=data.length();
        while(i<n) {
            string value="";
            while(i<n&&data[i]!=' ')value+=data[i++];
            TreeNode *node=0;
            if (value!="#") node=new TreeNode(stoi(value));
            nodes.push_back(node);
            i++;
        }
        int idx=0;
        TreeNode *root=recons(nodes,idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
