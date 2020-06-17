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
