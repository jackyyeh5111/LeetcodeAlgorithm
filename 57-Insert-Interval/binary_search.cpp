/* 
    time: O(logn)
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto comp = [](const vector<int>& newInterval, const vector<int>& interval) {
            return newInterval[0] < interval[0];
        };
        auto p1 = upper_bound(intervals.begin(), intervals.end(), newInterval, comp);

        if (p1 != intervals.begin()) {
            auto prev_p = prev(p1);
            if ((*prev_p)[1] >= newInterval[0]) {
                p1 = prev_p;
                newInterval[0] = (*prev_p)[0];
            }
        }

        auto comp2 = [](const vector<int>& newInterval, const vector<int>& interval) {
            return newInterval[1] < interval[0];
        };
        auto p2 = upper_bound(intervals.begin(), intervals.end(), newInterval, comp2);

        if (p2 != intervals.begin()) {
            auto prev_p = prev(p2);
            if ((*prev_p)[1] > newInterval[1])
                newInterval[1] = (*prev_p)[1];
        }

        intervals.erase(p1, p2);
        intervals.insert(p1, newInterval);
        return intervals;
    }
};

/* 
     A   B   C   D  
    ___ ___ ___ ___
      ________
 
    A   B   C   D  
    ___ ___ ___ ___
        ________
    
    A     B   C   D  
    ___   ___ ___ ___
        ________
 
    1. upper_bound(newInterval.start) = pointer B 
    2. check if A overlaps with newInterval
 
    A   B   C   D  
    ___ ___ ___ ___
       ________
 
    A   B   C   D  
    ___ ___ ___   ___
         ________
    
    A     B   C       D  
    ___   ___ _____   ___
          ________
    
    upper_bound(newInterval.end) = pointer D

    1. Remove [p1, p2]
 */