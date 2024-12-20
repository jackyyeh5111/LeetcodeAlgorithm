#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 
    complete binary tree

        0
      /   \
    1      2

    N = 2
*/
vector<TreeNode*> generateCompleteBinaryTree(int N) {
    // A complete binary tree cannot have an odd number of nodes if N > 1
    if (N <= 0) return {};
    
    vector<TreeNode*> result;
    
    if (N == 1) {
        result.push_back(new TreeNode(0));
        return result;
    }
    
    for (int leftSize = 1; leftSize <= N - 1; leftSize++) {
        // leftSize = 1
        // rightSize = 0
        int rightSize = N - 1 - leftSize;
        
        // Generate all left and right subtrees with corresponding sizes
        vector<TreeNode*> leftSubtrees = generateCompleteBinaryTree(leftSize);
        vector<TreeNode*> rightSubtrees = generateCompleteBinaryTree(rightSize);
        
        // Combine each left subtree with each right subtree
        for (TreeNode* left : leftSubtrees) {
            for (TreeNode* right : rightSubtrees) {
                TreeNode* root = new TreeNode(0); // Create root node
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }
    
    return result;
}

// Helper function to print the tree structure
void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << root->val << endl;
    printTree(root->left, depth + 1);
}

int main() {
    int N = 3; // Example: Generate all complete binary trees with 3 nodes
    vector<TreeNode*> trees = generateCompleteBinaryTree(N);
    
    cout << "Number of complete binary trees with " << N << " nodes: " << trees.size() << endl;
    
    // Print all trees
    for (TreeNode* tree : trees) {
        cout << "Tree:" << endl;
        printTree(tree);
        cout << endl;
    }
    
    return 0;
}
