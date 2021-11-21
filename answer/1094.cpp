/*
    [# of person, start point, end point]
    create a vector of pair. first: position, second: persons to get on the vehicle.
    sort in respect to position/
    accumulate checek how many ppl on the veehiclee now, if larger than capacity, return fasle.
    T:O(n+nlogn+n)/S:O(n)
    -----
    try to reduce time/space complexity
    sort has theory lower bound O(nlogn) in comparing sort.
    But if we use BUCKET SORT, we can reduce to T:O(n)
    0 <= trips[i][1] < trips[i][2] <= 1000
    We can even say we have T:O(1)/S:O(1)
*/

/***** use bucket sort *****/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<int> v(1000,0);
        for(auto trip:trips) {
            v[trip[1]-1]+=trip[0];
            v[trip[2]-1]-=trip[0];
        }
        int c=0;
        for (int i=0; i<1000; ++i) {
            c=max(0,c+v[i]);
            if (c>capacity) return false;
        }
        return true;
    }
};

/***** use Comparison Sort *****/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        map<int,int> m;
        for (auto trip:trips) {
            m[trip[1]]+=trip[0];
            m[trip[2]]-=trip[0];
        }
        int c=0;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            c=max(0,c+it->second);
            if(c>capacity) return false;
        }
        return true;
    }
};
