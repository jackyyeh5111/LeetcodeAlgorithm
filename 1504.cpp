/*
    First pass cumulative calculate horizontal rectangles.
    Second pass, we traverse down along to the bottom for checking current 1 is involved or not, vertical rectangel checking.
    T:O(n^3)
    -----
    Actually we can reduce to problem 85, max Rect in matrix.
    If stack is empty, meaning: all previous columns has more/equal ones than current column. So, the number of metrics can form is simply A[i] * (i + 1); (0-index)
    If stack is not empty, meaning: there is a shorter column which breaks our road. Now, the number of metrics can form is sum[i] += A[i] * (i - preIndex). And plus, we can form a longer submetrics with that previou shorter column sum[preIndex].

    Refers:
    https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/720265/Java-Detailed-Explanation-From-O(MNM)-to-O(MN)-by-using-Stack
    T:O(n^2)/S:O(n)
*/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int m=mat.size(), n=mat[0].size();
        int ans=0;
        vector<int> table(n,0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if  (mat[i][j]==0) table[j]=0;
                else table[j]++;
            }
            ans+=hist(table);
        }
        return ans;
    }

    int hist(vector<int> table)
    {
        stack<int> s;
        int n=table.size();
        vector<int> sum(n,0);
        for (int i=0; i<n; ++i) {
            while(!s.empty()&&table[s.top()]>=table[i]) s.pop();
            if (!s.empty()) {
                sum[i]=sum[s.top()];
                sum[i]+=(i-s.top())*table[i];
            }
            else sum[i]=table[i]*(i+1);
            s.push(i);
        }
        int ret=0;
        for (int s:sum) ret+=s;
        return ret;
    }
};


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i=0; i<m; ++i) {
            dp[i][0]=mat[i][0];
            for (int j=1; j<n; ++j) {
                if (mat[i][j]==0) dp[i][j]=0;
                else dp[i][j]=dp[i][j-1]+1;
            }
        }
        int ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans+=dp[i][j];
                int curmin=dp[i][j];
                for (int k=i+1; k<m; ++k) {
                    curmin=min(curmin,dp[k][j]);
                    ans+=curmin;
                }
            }
        }
        return ans;
    }
};
