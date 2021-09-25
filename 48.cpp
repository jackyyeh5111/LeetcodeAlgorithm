/***** Third Visit *****/
/*
    abcd   plhd
    efgh   okgc
    ijkl   njfb
    mnop   miea

    miea
    njfb
    okgc
    plhd

    T:O(n^2) 2 pass /S:O(1)
    -----
    (i,j) -> (n-j-1,n-i-1) -> (j,n-i-1)
    (0,0) -> (0,n-1) -> (n-1,n-1) -> (n-1,0) -> (0,0)

    # of iteration for each row: n-1 -> n-3 -> n-5 -> ...
    T:O(n^2) 1 pass /S:O(1)

*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        for (int i=n-1; i>0; --i) {
            for (int j=n-i-1; j<i; ++j) {
                 int x=n-i-1,y=j,prev=matrix[x][y];
                 for (int k=0; k<4; ++k) {
                     auto next=map(x,y,n);
                     int t=matrix[next.first][next.second];
                     matrix[next.first][next.second]=prev; prev=t;
                     x=next.first; y=next.second;
                 }
            }
       }
    }

    pair<int,int> map(int i, int j, int n)
    {
        return {j,n-i-1};
    }
};

/***** Second Visit *****/
/*
    In-place rotation
    swap \ diagonose then swap each col.
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0; i<n; ++i) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(n^2)
    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end()); //O(n)
        for (int j=0; j<matrix.size(); ++j) { //O(n^2)
            for (int i=0; i<=j; ++i) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }
};
