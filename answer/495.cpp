/*
    1,2,3,4,5 2
    1,2,3,4,5 3
    ^
        ^
    1,4 2
    ^
      ^
    -----
    for each position, if the nums in position+duration is in the list,
    then we add 1, else add duration.
    How do we check the nums if exist?
    -----
    2 ptr solution.(X)
    running ptr solution (V)
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int r=1,n=timeSeries.size(), ans=0;
        while(r<n) {
            ans+=min(timeSeries[r]-timeSeries[r-1],duration);
            r++;
        }
        return n>0?ans+duration:0;
    }
};
