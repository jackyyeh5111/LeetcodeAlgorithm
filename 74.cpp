/***** Third Visit *****/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0||matrix[0].size()==0) return false;
        int rows=matrix.size(), cols=matrix[0].size();
        int i=rows-1,j=0;
        while(i>=0&&j<cols) {
            if (matrix[i][j]==target) return true;
            if (matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    Since the matrix is sorted in respect to each row/col.
    We can start with left bottom position.
    if larger, than increase j; else decrease i.
    T:O(m+n)/S:O(1)
    -----
    Treat it as 1-d array and use binary search instead.
    T:O(logmn)/S:O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(), n=matrix[0].size();
        int i=m-1, j=0;
        while(i>=0&&j<n) {
            if (matrix[i][j]==target) return true;
            else if (matrix[i][j]>target) --i;
            else ++j;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(), n=matrix[0].size();
        int l=0, r=m*n;
        while(l<r) {
            int mid=(l+r)/2;
            int row=mid/n,col=mid%n;
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) r=mid;
            else l=mid+1;
        }
        return false;
    }
};

/***** First Visit *****/
/*
    Use binary search.
    n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
    an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // It is sorting in row major.
        // brute force: T:O(mn)
        // binary search in two directions T:O(logm+logn)
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        //vertical
        int rows=matrix.size()-1, cols=matrix[0].size()-1;
        int tp=0, dn=rows;
        while(tp<=dn) {
            int mid=(tp+dn)/2;
            if (matrix[mid][cols]==target) return true;
            else if (matrix[mid][cols]<target) tp=mid+1;
            else dn=mid-1;
        }
        if (tp==rows+1) return false;

        // horizontal
        int l=0, r=cols;
        while(l<=r) {
            int mid=(l+r)/2;
            if (matrix[tp][mid]==target) return true;
            else if(matrix[tp][mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;

    }
};
