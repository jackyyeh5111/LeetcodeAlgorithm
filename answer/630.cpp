/*
    courses[i] = [duration_i, lastDay_i]
    [[100,200],[200,1300],[1000,1250],[2000,3200]]
    return the max course we can take.
    -----
    brute force:
    enumerate all the combination order and find the max courses series.
    T:O(n!)/S:O(n)
    -----
    greedy? minheap to take the minima duration course
    [[2,10],[2,19],[3,19],[5,15],[5,16],[6,7],[8,14],[10,11]]
    -----
    BIS
    8,10 17,19 16,19 10,15 11,16 1,7 6,14 1,11
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(),courses.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        multiset<int> ms;
        int cur=0;
        for (auto &course:courses) {
            if (cur+course[0]<=course[1]) {
                cur+=course[0];
                ms.insert(course[0]);
            }
            else if (!ms.empty()&&*ms.rbegin()>course[0]){
                cur-=*ms.rbegin()-course[0];
                ms.erase(--ms.end());
                ms.insert(course[0]);
            }
        }
        return ms.size();
    }
};
