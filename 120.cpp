class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        /*
            require: S:O(n)
            thought:
                is DP available <-> is there induction?
                    minimumTotal[i]=minimumTotal[i-1]+lastLevel[i]||lastLevel[i-1]?
                    NO!!
                thus try greedy.
            --- recursive TLE ---
            T:O(depth^2), S:O(depth)
            --- DP ---
            DP works, but need an auxilary find min on the last vec whil top-
            down solution. If we apply bottom up, we can narrow down the
            candidate to the only one, which is the first entry of triangle.
        */
        // Top Down
        vector<int> dp(triangle.size(), 0);
        for (int row=0; row<triangle.size(); ++row) {
            int prev=dp[0];
            if(row>0) dp[row]=dp[row-1]+triangle[row][row];
            dp[0]+=triangle[row][0];
            for (int col=1; col<triangle[row].size()-1; ++col) {
                int tmp=dp[col];
                dp[col]=min(prev,dp[col])+triangle[row][col];
                prev=tmp;
            }
        }
        int ans=INT_MAX;
        for(int sum:dp) ans=min(ans,sum);
        return ans;
    }
};

/********************* Bottom Up *********************/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};
