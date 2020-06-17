/****************** Recursive ***************/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        // recursive
        if (matrix.size()==0||matrix[0].size()==0) return vector<int>{};

        return spiralOrder(matrix, 0, 0, matrix.size(), matrix[0].size());
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix, int row, int col, int h, int w)
    {
        // cout<<row<<","<<col<<","<<h<<","<<w<<endl;
        if (h==0||w==0) return vector<int>{};
        if (h==1) {
            vector<int> order;
            for (int i=0; i<w; ++i) order.push_back(matrix[row][col+i]);
            return order;
        }
        if (w==1) {
            vector<int> order;
            for (int i=0; i<h; ++i) order.push_back(matrix[row+i][col]);
            return order;
        }
        vector<int> internal = spiralOrder(matrix, row+1,col+1, h-2, w-2);
        vector<int> order;
        for (int i=col; i<col+w; ++i) order.push_back(matrix[row][i]);
        for (int i=row+1; i<row+h; ++i) order.push_back(matrix[i][col+w-1]);
        for (int i=col+w-2; i>=col; --i) order.push_back(matrix[row+h-1][i]);
        for (int i=row+h-2; i>=row+1; --i) order.push_back(matrix[i][col]);
        order.insert(order.end(), internal.begin(), internal.end());
        return order;
    }
};
/****************** iterative ***************/
class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector <int> res;
    int rowSize = matrix.size();
    if (rowSize==0) return res;
    int colSize = matrix[0].size();
    int lb=0,rb=colSize-1,ub=0,db=rowSize-1;// left bound, right bound, up bound, down bound;
    int direction = 0;
    int col=0,row=0;
    while (lb<=rb && ub<=db){
        res.push_back(matrix[row][col]);
        switch (direction){
            case 0:  //  right
                if (col>=rb) {direction = 1;row=row+1;ub++;} else col=col+1;
                break;
            case 1: // down
                if (row>=db) {direction = 2;col=col-1;rb--;} else row=row+1;
                break;
            case 2: // left
                if (col<=lb) {direction = 3;row=row-1;db--;} else col=col-1;
                break;
            default:  // up
                if (row<=ub) {direction = 0;col=col+1;lb++;} else row=row-1;
        }
    }
    return res;
}
};
