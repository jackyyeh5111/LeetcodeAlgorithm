/*
    clustering T:O(n)
    graham's algo T:O(nlogn)
    arange T:O(n)
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        /*
            Use multiset as a priority queue.
            keep tracking (l,h),(r,h)
            Use a priority q to track tallest point.
            while we meet the end point of building, remove it from the priority queue.
            The skyline points are the points with height changing,
            i.e. every local max point, i.e. every convex point

            refer: https://youtu.be/GSBLe8cKu0s
        */
        vector<int> cur(2,0);
        vector<vector<int>> ans;
        // multiset will sort by first entry
        multiset<vector<int>> seq;
        for (auto building:buildings) {
            seq.insert(vector<int>{building[0],-building[2]});
            seq.insert(vector<int>{building[1],building[2]});
        }
        multiset<int> height;
        height.insert(0);
        for (auto building:seq) {
            if (building[1]<0) height.insert(-building[1]);
            else height.erase(height.find(building[1]));
            if (*height.rbegin()!=cur[1]) {
                cur[0]=building[0];
                cur[1]=*height.rbegin();
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
