/***** Second Visit *****/
/*
    [1,2],[1,3],[2,3],[3,4]
    [1,7] [2,3] [4,5] [5,6] [5,8]
    1 2 3 4 5 6 7 8
    _____________
      ___
          ___
              ___
            _______
    greedy select the smallest upper
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if (n<2) return 0;
        int cmax=intervals[0][1], keep=1;
        for (int i=1; i<n; ++i) {
            if (intervals[i][0]<cmax) {
                cmax=min(cmax,intervals[i][1]);
            }
            else {keep++; cmax=intervals[i][1];}
        }
        return n-keep;
    }
};

/***** First Visit *****/
/*
    [1,2],[1,3],[2,3],[3,4]
    1 2 3 4
    ___
    _____
      ___
        ___
    =====
    brute force:
    enumerate all possible sub intervals and check
    T:O(2^n*n)/S:O(n)
    =====
    Greedy:
    While we find overlap, remove the one with larger end point.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(),intervals.end());
        int cur_max=intervals[0][0], ans=0;
        for (auto interv:intervals) {
            if (interv[0]>=cur_max) cur_max=interv[1];
            else {
                cur_max=min(cur_max,interv[1]);
                ans++;
            }
        }
        return ans;
    }
};
