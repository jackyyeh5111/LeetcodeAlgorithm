/***** Fourth Visit *****/
/*
    multiset<pair<int,int>> // x coord, height
    pos height: involve this building
    neg height: kick off this building

    multiset<int> heights
    record all heights we need to take care so far.
    T:O(nlogn)/S:O(n)
*/

/***** Third Visit *****/
/*
    sort x coord first, we will handle each point in x-increasing/y-decreasing order.
    For each building, we will have 2 points in our list, (L,H), (R,-H). Negative height means out of the building's width.
    Maintain a sorted array to find out the current max y coord and specific height.
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int,int>> s;
        multiset<int> q;
        vector<vector<int>> ans;
        for (auto building:buildings) {
            s.push_back({building[0],building[2]});
            s.push_back({building[1],-1*building[2]});
        }
        sort(s.begin(),s.end(),[](auto a, auto b){
            if (a.first==b.first) return a.second>=b.second;
            else return a.first<=b.first;
        });
        q.insert(0); int cur_max=0;
        for (auto building:s) {
            if (building.second<0)
                q.erase(q.find(-1*building.second));
            else q.insert(building.second);
            if (*(q.rbegin())!=cur_max) {
                cur_max=*(q.rbegin());
                ans.push_back({building.first,cur_max});
            }
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    use a stack to record buildings in increasing x order.
    [ [2 9 10], [3 7 15], [5 12 12] ]
    stack empty:
        choose coord[0],coord[2]
        push into stack
    not empty:
        H is higher then previous one
            choose coord[0],coord[2]
            push into stack
        H is lower then k previous buildings
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        multiset<vector<int>> seq;
        for (auto building:buildings){
            seq.insert({building[0],-building[2]});
            seq.insert({building[1],building[2]});
        }
        vector<vector<int>> ans;
        vector<int> cur(2,0);
        multiset<int> heights;
        heights.insert(0);
        for (auto building:seq) {
            if (building[1]<0) heights.insert(-building[1]);
            else heights.erase(heights.find(building[1]));
            if (*heights.rbegin()!=cur[1]) {
                cur[0]=building[0];
                cur[1]=*heights.rbegin();
                ans.push_back(cur);
            }
        }
        return ans;
    }
};

/***** First Visit *****/
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
