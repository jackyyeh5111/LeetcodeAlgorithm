/*
    [[1,2,2,1],
     [3,1,2],
     [1,3,2],
     [2,4],
     [3,1,2],
     [1,3,1,1]]

    sum of bricks in each row wont get integer overflow
    1 <= rows, cols <= 10000
    -----
    previous sum for each row, and utlize a map to record frequency
    max frequency -> most ignore edge -> return rows - maxFreq
    inside checking, ignore the last one due to boundary

    T:O(mn)/S:O(mn)
    -----
    [1,2,3] -> [1,3,6]
    edge case [1]
    -----
    1356
    346
    26
    346
    1456
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall)
    {
        unordered_map<int,int> mp;
        int cols=0;
        for (auto &w:wall) {
            int csum=0;
            for (int &n:w) {
                csum+=n;
                mp[csum]++;
            }
            cols=csum;
        }
        int maxFreq=0;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            if (it->first==cols) continue;
            maxFreq=max(maxFreq,it->second);
        }
        return wall.size()-maxFreq;
    }
};
