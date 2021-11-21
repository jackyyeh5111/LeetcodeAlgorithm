class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        /*
        Typical finite state machine, you will have to build an automata that
        changes states at each tick; given that we are basically only changing
        6 bits, states can only have 64 (2 ** 6) different values.

        Once a cycle is detected (ie: it matches the first value in seen)
        return the pre-stored state in seen with index equal to
        (N-1) % seen.size(), with seen.size() telling us how big the loop
        interval 
        */
        vector<vector<int>> seen;
        for (int i=0; i<N; ++i) {
            int prev=cells[0];
            for (int idx=1; idx<7; ++idx) {
                int tmp=cells[idx];
                cells[idx]=!(prev^cells[idx+1]);
                prev=tmp;
            }
            cells[0]=0; cells[7]=0;
            if(seen.size()&&seen[0]==cells) return seen[(N-1)%seen.size()];
            else seen.push_back(cells);
        }
        return cells;
    }
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        /*
            bit minupulation XOR
            0 1 0 1 1 0 0 1
            -------- 1D DP TLE --------
        */
        for (int i=0; i<N; ++i) {
            int prev=cells[0];
            for (int idx=1; idx<7; ++idx) {
                int tmp=cells[idx];
                cells[idx]=!(prev^cells[idx+1]);
                prev=tmp;
            }
            cells[0]=0; cells[7]=0;
        }
        return cells;
    }
};
