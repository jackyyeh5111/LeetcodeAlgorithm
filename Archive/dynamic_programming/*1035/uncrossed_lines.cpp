/*
 *  DP, The Longest Common Subsequence
 */
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int a_size = A.size();
        int b_size = B.size();
        int table[a_size+1][b_size+1] = { {0} };
        memset(table, 0, sizeof(table));
        for (int i=1; i <= a_size; ++i) {
            for (int j=1; j <= b_size; ++j) {
                table[i][j] = A[i-1]==B[j-1] ? table[i-1][j-1] + 1 : max(table[i-1][j],table[i][j-1]);
            }
        }
        return table[a_size][b_size];
    }
};
