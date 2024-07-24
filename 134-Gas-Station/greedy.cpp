class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gain = 0, cur_gain = 0;
        int ans = 0;
        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            total_gain += gain;
            cur_gain += gain; 

            if (cur_gain < 0) {
                ans = i + 1;
                cur_gain = 0;
            }
        }
        return total_gain < 0 ? -1 : ans;
    }
};

/* 
    Clarification:
    1. non-negative number in both arrays
    2. total_gain >= 0

     gas: [2, 3, 5  3   6 ]
    cost: [3, 4, 3  6   3 ]
    gain: -1. -1 2  -3  3
 
    gas: [2, 3, 4]
   cost: [3, 3, 3]
         -1. -1  2 

    -1 0 1
    1 -1 0
 */