Use binary search.

n * m matrix convert to an array => matrix[x][y] => a[x * m + y]

an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];

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
