
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N)
    {
        if (N%2==0) return {};
	    vector<vector<TreeNode*>> dp(N/2+1,vector<TreeNode*>{});
        dp[0].push_back(new TreeNode()); // N=1
	    for (int i=3; i<=N; i+=2) {
	    	for (int j=1; j<i; j+=2) {
		        auto left_trees=dp[j/2];
		        auto right_trees=dp[(i-j-1)/2];
		        for (auto l:left_trees) {
                    for (auto r:right_trees){
                        TreeNode* node=new TreeNode();
                        node->left=l; node->right=r;
                        dp[i/2].push_back(node);
                    }
                }
		    }
        }
        return dp[N/2];
    }
};
