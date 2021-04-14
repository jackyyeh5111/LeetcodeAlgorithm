/*
    target = 12
    position = [10,8,0,5,3]
    speed =    [2, 4,1,1,3]

    sort first
    0  3 5 8 10
    1  3 1 4 2
    12 3 7 1 1  <-- time to destination,  it should be mono STRICT increasing
    __ ___ ___ -> 3 car fleets

    GIVEN: All initial positions are different.

    Use a stack from right to left, check if the current car will crash into the car which is the top of stack
    Each element inside the stack represents a car fleet.

    10
    [0, 2,  4]
    [2, 3,  1]
     5  8/3 6
*/
// w. stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        set<pair<int,int>> seqs;
        int n=position.size();
        for (int i=0; i<n; ++i)
            seqs.insert({position[i],speed[i]});
        stack<double> s;
        for (auto it=seqs.rbegin(); it!=seqs.rend(); ++it) {
            double time=(target-it->first)/(double)it->second;
            if (s.empty()||s.top()<time) s.push(time);
        }
        return s.size();
    }
};

// w.o. stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        set<pair<int,int>> seqs;
        int n=position.size(), ans=0;
        for (int i=0; i<n; ++i)
            seqs.insert({position[i],speed[i]});
        double cur=0;
        for (auto it=seqs.rbegin(); it!=seqs.rend(); ++it) {
            double time=(target-it->first)/(double)it->second;
            if (time>cur) {cur=time; ans++;}
        }
        return ans;
    }
};
