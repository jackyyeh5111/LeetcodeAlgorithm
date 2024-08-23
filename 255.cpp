class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1);
    }
    bool dfs(const vector<int> &preorder, int start, int end) {
        if (start > end) return true;
        int idx = start + 1;
        // find left subtree
        while(idx <= end && preorder[idx] < preorder[start])
            idx++;
        // check right subtree nodes all greater than root
        int left_end = idx - 1;
        while(idx <= end) {
            if (preorder[idx] <= preorder[start]) return false;
            idx++;
        }
        return dfs(preorder, start + 1, left_end) && dfs(preorder, left_end+1, end);
    }
    
};

/* 
    Check all nodes in left subtree is less than root,
    all nodes in right subtree is greater than root.

    preorder: [6 2 0 4 8]
    left subtree: 2, 0, 4
    right subtree: 8

                       [6]  
                /              \
             [2]                 [8]   
           /     \          
        [0]       [4]          
    
    preorder: [1 2 0 4 8]
                 r l
    left subtree: 1 0 2
    right subtree: 

                       [1]  
                /              \
             [2]                 [8]   
           /     \          
        [0]       [4]          
    
    preorder: [3 2 0 4 8]
                 l   r    
    left subtree: 1 0 2
    right subtree: 

                       [3]  
                /              \
             [2]                 [8]   
           /     \          
        [0]       [4]          

                       [3]  
                /              \
             [2]                 [4]   
           /                  / 
        [0]                 [8]
 
    preorder: [6 2 0 4 7 8]
    left subtree: 2 0 4
    right subtree: 7 8

                       [6]  
                /              \
             [2]                 [8]   
           /     \          
        [0]       [4] 
                 /
                [7]         
    
    preorder: [1 2 0 4 8]
                 r l
    left subtree: 1 0 2
    right subtree: 
 
    

    - skew tree
        preorder: [3 2 1]
        left subtree: [2 1]
        left subtree: []
                 [3]  
                / 
             [2] 
            /
         [1]
 */