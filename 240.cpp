/***** Second Visit *****/
/*
    brute force:
    T:O(n^2)/S:O(1) that iterate over all elments.
    -----
    Start from left bottom and do a linear search.
    T:O(m+n)/S:O(1)
    -----
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(), n=matrix[0].size();
        int i=m-1, j=0;
        while (i>=0&&j<n) {
            if (matrix[i][j]==target) return true;
            else if (matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }
};

/***** First Visit *****/
/*
    brute force: iterate each num
    T:O(nm)/S:O(1)
    ----------
    binary search in each row
    T:O(mlogn)/S:O(1)
    ----------
    binary search alogn first column and start finding
        need larger: ->
        need smaller: ^
    T:O(logm + m + n)/S:O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0||matrix[0].size()==0) return false;

        int rows=matrix.size(), cols=matrix[0].size();
        int l=0, r=rows-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if (matrix[mid][0]==target) return true;
            else if (matrix[mid][0]>target) r=mid-1;
            else l=mid+1;
        }
        // start traverse from matrix[mid,0]
        int row=r, col=0;
        while(row>=0&&col<cols) {
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) row--;
            else col++;
        }
        return false;
    }
};
/*
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
5
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
20
[[-5]]
-10
*/
