/***** Third Visit *****/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int left=0,right=n-1,top=0,bottom=n-1;
        int row,col,cur=1;
        while (left<=right||top<=bottom) {
            col=left; row=left;
            while (col<right) ans[row][col++]=cur++;
            while (row<bottom) ans[row++][col]=cur++;
            while (col>left) ans[row][col--]=cur++;
            while (row>top) ans[row--][col]=cur++;
            left++; right--;
            top++; bottom--;
        }
        if (n%2) ans[row][col]=cur;
        return ans;
    }
};

/***** Second Visit *****/
/*
    reduce to problem 52.
    Here we adopt iterative approach.
    T:O(n^2)/S:O(n^2)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int lb=0,rb=n-1,tb=0,db=n-1;
        int row=0,col=0,direction=0,counter=1;
        while(lb<=rb&&tb<=db) {
            ans[row][col]=counter++;
            direction=direction%4;
            switch(direction) {
                case 0:
                    if (col==rb) {direction++;row++;tb++;} else col++;
                    break;
                case 1:
                    if (row==db) {direction++;col--;rb--;} else row++;
                    break;
                case 2:
                    if (col==lb) {direction++;row--;db--;} else col--;
                    break;
                case 3:
                    if (row==tb) {direction++;col++;lb++;} else row--;
                    break;
            }
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int lb=0, rb=n-1,ub=0, db=n-1;
        int direction=0;
        int row=0, col=0;
        int counter=1;
        while(lb<=rb&&ub<=db) {
            matrix[row][col]=counter++;
            switch(direction){
                case 0:
                    if (col<rb) col++;
                    else { direction=1; row++; ub++; }
                    break;
                case 1:
                    if (row<db) row++;
                    else { direction=2; rb--; col--; }
                    break;
                case 2:
                    if (col>lb) col--;
                    else { direction=3; db--; row--; }
                    break;
                case 3:
                    if (row>ub) row--;
                    else { direction=0; lb++; col++; }
                    break;

            }
        }
        return matrix;
    }
};
