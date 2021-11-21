/*
    1 2 3 4
    5 6 7 8
    9 0 1 2

    0 1 2 3 ...
    T:O(mn)/S:O(mn)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return {};
        int m=matrix.size(), n=matrix[0].size();
        bool goup=true;
        vector<int> ans;
        for (int k=0; k<m+n-1; ++k) {
            if (goup) {
                int i=min(k,m-1), j=k-i;
                while (i>=0&&j<n) {
                    ans.push_back(matrix[i][j]);
                    i--; j++;
                }
            }
            else {
                int j=min(k,n-1), i=k-j;
                while (i<m&&j>=0) {
                    ans.push_back(matrix[i][j]);
                    i++; j--;
                }
            }
            goup = !goup;
        }
        return ans;
    }
};
