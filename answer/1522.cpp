/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
    If we have only one node, return 0;
    postorder traversal
    if (!root->left&&!root->right) return 0;
    ans -> the longest path across this root node.
    int postorder(Node *root, int &ans)
    {
        if (root is a leaf node) return 0;
        vector<int> paths;
        for (Node *child:root->children) {
            paths.push_back(postorder(child))
        }
        if (paths.size()>2) ans=max(ans,largest + second Largest)
        else if (paths.size()==1) ans=max(ans,paths[0])
        else
    }

    T:O(n)/S:O(n)
*/

/*
    [1] ans=0;
    [1,null,3,2,4,null,5,6]
*/
class Solution {
public:
    int diameter(Node* root) {
        int ans=0;
        postOrder(root,ans);
        return ans;
    }

    // ans the longest path across current root node.
    int postOrder(Node *root, int &ans)
    {
        if (root->children.empty()) return 0;
        int path1=-1, path2=-1;
        for (Node *child:root->children) {
            int curPath=postOrder(child,ans)+1;
            if (curPath>path1) {path2=path1; path1=curPath; }
            else if (curPath>path2) path2=curPath;
        }
        if (path1!=-1&&path2!=-1) ans=max(ans,path1+path2);
        else ans=max(ans,path1);
        return path1;
    }
};
