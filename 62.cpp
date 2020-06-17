
/*
combination thought
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // O(n) comes with math C^(m-1+n-1)_(n-1)
        double up=1.0; double down=1.0;
        if (m<n) swap(m,n);
        for(int i=0; i<n-1; ++i) {
            up*=m+n-2-i;
            down*=n-1-i;
        }
        return (int)(up/down);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // O(2^n) comes with math C^(m-1+n-1)_(n-1)
        return comb(m+n-2, n-1);
    }

    int comb(int m, int n)
    {
        if (m==n||n==0) return 1;
        return comb(m-1,n)+comb(m-1,n-1);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // O(mn) comes with math C^(m-1+n-1)_(n-1)
        if (n==1) return 1;
        vector<vector<double>> table(m-1+n-1,vector<double>(m-1+n-1,0));
        for (int i=0; i<m-1+n-1; ++i) {
            table[i][i]=1;
            table[i][0]=i+1;
        }
        for (int i=1; i<m-1+n-1; ++i) {
            for (int j=1; j<m-1+n-1; ++j) {
                if (table[i][j]!=0) continue;
                table[i][j]=table[i-1][j]+table[i-1][j-1];
            }
        }
        return table[m-1+n-1-1][n-1-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // O(n(n-m)) comes with math C^(m-1+n-1)_(n-1)
        if (n==1) return 1;
        if (m<n) swap(m,n);
        vector<int> table(n,1);
        for (int i=0; i<m-1; ++i) {
            for (int j=1; j<n; j++) table[j]+=table[j-1];
        }
        return table[n-1];
    }

};

/*
Since the robot can only move right and down, when it arrives at a point, it either arrives from left or above. If we use dp[i][j] for the number of unique paths to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j]. Moreover, we have the base cases dp[0][j] = dp[i][0] = 1 for all valid i and j.

The above solution runs in O(m * n) time and costs O(m * n) space. However, you may have noticed that each time when we update dp[i][j], we only need dp[i - 1][j] (at the previous row) and dp[i][j - 1] (at the current row). So we can reduce the memory usage to just two rows (O(n)).

Further inspecting the above code, pre[j] is just the cur[j] before the update. So we can further reduce the memory usage to one row.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};
