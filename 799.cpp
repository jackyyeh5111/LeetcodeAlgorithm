/***** First Visit *****/
/*
                    U                   1
                U       U               11
            U       U       U           121
        U       U       U       U       1331
    U       U       U       U       U
    -----
    The needed cups to full each level: 1 3 7 15 31 ... 2^(n-1)
    1. Find the previous needed cupds.
    2. If enough, find the pascal num of row: query_row
    3. calculate proportion according to the num from 2. If >= 1, return 1.
    T:O(n)/S:O(n) TAIL TO DO IT WITH CALCULATION
    -----
    Conduct the real process
    T:O((query_row+1)^2)/S:O((query_row+1)^2)
    -----
	Space complexity could be reduced to linear.
*/

// 1-d DP
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> towel(101,vector<double>(101,0.0));
        towel[0][0]=poured;
        for (int i=0; i<=query_row; ++i) {
            for (int j=0; j<=i+1; ++j)  {
                double flow=(towel[i][j]-1.0)/2.0;
                if (flow>0) {
                    towel[i+1][j]+=flow;
                    towel[i+1][j+1]+=flow;
                }
            }
        }
        return min(1.0,towel[query_row][query_glass]);
    }
};

// 2-d DP
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> towel(101,vector<double>(101,0.0));
        towel[0][0]=poured;
        for (int i=0; i<=query_row; ++i) {
            for (int j=0; j<=i+1; ++j)  {
                double flow=(towel[i][j]-1.0)/2.0;
                if (flow>0) {
                    towel[i+1][j]+=flow;
                    towel[i+1][j+1]+=flow;
                }
            }
        }
        return min(1.0,towel[query_row][query_glass]);
    }
};
