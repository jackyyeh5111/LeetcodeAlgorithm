class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B)
    {
        // LCS T:O(n^2), S:O(n^2)
        int a=A.size()+1;
        int b=B.size()+1;
        vector<vector<int>> table(a, vector<int>(b, 0));
        for (int i=1; i<a; ++i){
            for (int j=1; j<b; ++j) {
                if (A[i-1]==B[j-1]) table[i][j] = table[i-1][j-1] + 1;
                else table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
        return table[a-1][b-1];
    }
};
