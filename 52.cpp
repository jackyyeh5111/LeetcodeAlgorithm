/***** Fourth Visit *****/
/*
    T:O(n^n*O(check))/S:O(n)
    use a vector<bool> for O(1) checking
    \ i-j
    - i
    / i+j
*/

/***** Third Visit *****/
/*
    DFS (Backtacking)
    T:O(4^9 * O(check))
    question is about how to check if feasible?

    Check: T:O(n)
    horizontal
    \: i-j
    /: i+j

    We can only use 1-D vector for saving the pos we put queen.
    i.e. [3,1,4,2]
*/

/***** Second Visit *****/
/*
    Typical backtracking problem.
    Try out all possible placements, n^n.
    For feasible checking, it takes another O(n)

    Since n is small, i.e. 1<n<9, we dont need to worry about TLE.
    Note that we only need to return the num of possible combs, we just need to maintain 1-d array for placement checking.
    T:O(n^(n+1))/S:O(n)
*/
class Solution {
public:
    int totalNQueens(int n)
    {
        vector<int> table(n,-1);
        int ans=0;
        help(table,0,ans, n);
        return ans;
    }

    void help(vector<int> &table, int col, int &ans, int n)
    {
        if (col==n) ans++;
        for (int i=0; i<n; ++i) {
            if (!isfeasible(table,i,col)) continue;
            table[col]=i;
            help(table,col+1,ans,n);
        }
    }

    bool isfeasible(vector<int> &table, int row, int col)
    {
        for (int i=0; i<col; ++i) {
            if (table[i]==row) return false;
            if (table[i]-i==row-col) return false;
            if (table[i]+i==row+col) return false;
        }
        return true;
    }
};

/***** First Visit *****/
class Solution {
public:
    int count = 0;
    vector<bool> angle45;
    vector<bool> angle135;
    vector<bool> angle0;

    // T:O(n!), n x n-1 x n-2 x n-3 x ... x 1
    // S:O(n)
    int totalNQueens(int n)
    {
        angle45 = vector<bool>(2*n-1,0);
        angle135 = vector<bool>(2*n-1,0);
        angle0 = vector<bool>(n,0);
        backtracking(0, n);
        return count;
    }

    void backtracking(int row, int n)
    {
        if (row==n) count++;
        for (int col=0; col<n; ++col) {
            int idx45 = row+col;
            int idx135 = n-1+col-row;
            if (angle0[col] ||angle45[idx45]||angle135[idx135])continue;

            angle0[col]=true; angle45[idx45]=true; angle135[idx135]=true;
            backtracking(row+1, n);
            angle0[col]=false; angle45[idx45]=false; angle135[idx135]=false;
        }
    }
};
