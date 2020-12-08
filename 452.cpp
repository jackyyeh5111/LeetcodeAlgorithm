/*
    sort first, condition: a.first<b.first,  a.second>=b.second
    return find the nums of non-overlap
    Note that keep  tracking min rangne.
    T:O(nlogn)/S:O(1)
    -----
    input:     [1,6],[2,8],[7,12],[10,16]
    min range:  1,6   2,6   7,12   10,12
    k:           1     1     2       2   <-- return k.
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int k=1, n=points.size();
        if (n<=1) return n;
        sort(points.begin(),points.end(),[](auto a, auto b){
            return a[0]==b[0]?a[1]>=b[1]:a[0]<b[0];
        });
        int p[2]={points[0][0],points[0][1]};
        for (int i=1; i<n; ++i) {
            if (p[1]<points[i][0]) {
                p[0]=points[i][0];
                p[1]=points[i][1];
                k++;
            }
            else {
                p[0]=max(p[0],points[i][0]);
                p[1]=min(p[1],points[i][1]);
            }
        }
        return k;
    }
};
