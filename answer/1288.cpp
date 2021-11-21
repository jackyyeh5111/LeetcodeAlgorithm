/*
    1,4 2,8 3,6
    1. sort first in terms of a<b, if a==b, return c<d
    2. if a==c, find the largest b/d in same a/c.
    3. else if d<=c, it is covered
    T:O(nlogn)/S:O(1) in-place sorting
    -----
    1,2 1,3 1,4 2,1 2,3 2,5 2,6 2,7 3,1 3,3 4,8
*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            if (a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        int i=0, n=intervals.size(),t=-1,ans=0;
        while (i<n) {
            while(i<n-1&&intervals[i+1][0]==intervals[i][0]) ++i;
            if (intervals[i][1]>t) ans++;
            t=max(t,intervals[i][1]);
            ++i;
        }
        return ans;
    }
};
