/***** Second Visit *****/
/*
    Given a tree, return the min flip times to make this tree's preorder same as voyage.
    root = [1,2,3], voyage = [1,3,2]
    preorder: NLR

    key: value is unique.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        vector<int> ans;
        int idx=0;
        if (!check(root,voyage,idx,ans)) return {-1};
        else if (idx!=(int)voyage.size()) return {-1};
        else return ans;
    }

    bool check(TreeNode *root, vector<int> &voyage, int &idx, vector<int> &ans)
    {
        if (!root) return true;
        else if (root->val!=voyage[idx]) return false;
        idx++;
        bool valid=true;
        if (!check(root->left,voyage,idx,ans)) {
            swap(root->left,root->right);
            valid=check(root->left,voyage,idx,ans)&&valid;
            ans.push_back(root->val);
        }
        valid=valid&&check(root->right,voyage,idx,ans);
        return valid;
    }
};

/***** First Visit *****/
/*
    brute force:
    enumerate all possible preorder then compare wih voyage
    T:O(2^n)/S:O(n)
    -----
    Directly conduct preorder and check child left child.
    check:
        left child if we should switch left / right.
        current node to check if possible.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        int idx=0;
        vector<int> ans;
        bool check=help(root,voyage,idx,ans);
        if (!check||idx!=voyage.size()) ans={-1};
        return ans;
    }

    bool help(TreeNode *root, vector<int> &voyage, int &idx, vector<int> &ans)
    {
        if (!root) return true;
        if (idx>=voyage.size()||root->val!=voyage[idx]) return false;
        if (root->left&&idx<voyage.size()-1&&root->left->val!=voyage[idx+1]) {
            swap(root->left,root->right);
            ans.push_back(root->val);
        }
        idx++;
        bool left=help(root->left,voyage,idx,ans);
        bool right=help(root->right,voyage,idx,ans);
        return left&&right;
    }
};
