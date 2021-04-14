/***** Fourth Visit *****/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return deserialize(data,i);
    }

    TreeNode* deserialize(string data, int &i) {
        if (i>=data.length()||data[i]=='#') {i++; return 0;}
        int val=0; bool neg=data[i]=='-';
        if (neg) i++;
        while (i<data.length()&&isdigit(data[i]))
            val=val*10+(data[i++]-'0');
        if (neg) val*=-1;
        TreeNode *node=new TreeNode(val);
        i++;
        node->left=deserialize(data,i);
        i++;
        node->right=deserialize(data,i);
        return node;
    }
};

/***** Third Visit *****/
/*
    preorder+inorder-> unique tree
    T:O(n) 2 pass /S:O(n)
    -----
    Try another approach for only 1 pass traversal
    N1N2##N345
    T:O(n)/S:O(n)
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        // cout<<"encode: "<<ans<<endl;
        return ans;
    }

    void preorder(TreeNode *root, string &ret)
    {
        if (!root) {ret+="#,"; return;}
        ret+=to_string(root->val)+",";
        preorder(root->left, ret);
        preorder(root->right, ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return construct(data, idx);
    }

    TreeNode *construct(string data, int &i)
    {
        if (data[i]=='#') {i+=2; return 0;}
        int num=0, sign=1;
        if (data[i]=='-') {sign=-1; ++i;}
        while(data[i]!=',') num=num*10+(data[i++]-'0');
        TreeNode *node=new TreeNode(sign*num);
        i++;
        node->left=construct(data,i);
        node->right=construct(data,i);
        return node;
    }
};

/***** Second Visit *****/
/*
    Use preorder traversal to avoid level order traversal approach which takes null as consideration. Therefore its time complexity could be reduced from T:O(2^n)->T:O(n)
*/
class Codec {
public:

    void preorder(TreeNode* root, string &encode)
    {
        if(!root) encode+="#,";
        else {
            encode+=to_string(root->val)+",";
            preorder(root->left, encode);
            preorder(root->right, encode);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string encode="";
        preorder(root,encode);
        return encode;
    }

    TreeNode* recon(vector<TreeNode*> nodes, int &idx)
    {
        if (idx>=nodes.size()) return 0;
        TreeNode *node=nodes[idx++];
        if (!node) return 0;
        node->left=recon(nodes,idx);
        node->right=recon(nodes,idx);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        // cout<<data<<endl;
        vector<TreeNode*> nodes;
        int i=0, n=data.length();
        while (i<n) {
            string val="";
            while(i<n&&data[i]!=',') val+=data[i++];
            if (val!="#") nodes.push_back(new TreeNode(stoi(val)));
            else nodes.push_back(0);
            i++;
        }
        int idx=0;
        return recon(nodes,idx);
    }
};

/***** First Visit *****/
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
