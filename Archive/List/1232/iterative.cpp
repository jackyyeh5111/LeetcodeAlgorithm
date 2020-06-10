// Speed up for disable C/C++ print function synchronization,
//     i.e. printf v.s. cout.
// Disable cout flush before cin. This will cause print function
//     interleaving out.
// auto speed=[]()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

class Solution {
public:
    /*
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if (coordinates.size() <=2) return true;
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) /
            (double)(coordinates[1][0] - coordinates[0][0]);
        for ( int i=2; i<coordinates.size(); ++i ) {
            double current_slope = (double)(coordinates[i][1] - coordinates[i-1][1]) /
                (double)(coordinates[i][0] - coordinates[i-1][0]);
            if (current_slope != slope) return false;
        }
        return true;
    }
    */

    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if (coordinates.size() <=2) return true;
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) /
            (double)(coordinates[1][0] - coordinates[0][0]);
        for ( int i=2; i<coordinates.size(); ++i ) {
            if (slope*coordinates[i][1] != coordinates[i][0]) return false;
        }
        return true;
    }
    // Use formula:
    // y = slope * x + b
};
