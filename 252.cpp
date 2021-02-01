/*
    sorting
    T:O(nlogn)/S:O(1)
    -----

*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            if (a[0]<b[0]) return true;
            else if (a[0]>b[0]) return false;
            else return a[1]<b[1];
        });
        int n=intervals.size(),i=0;
        while (i<n-1) {
            if (intervals[i][1]>intervals[i+1][0]) return false;
            i++;
        }
        return true;
    }
};
