/*
    consider it as a stack problem.
    for each car, it will only crash the right and slow one.

    if the crash time of c c1 is later than c1 c2, it means c won't catch c1, which indicates that c1 will crash c2 first, then we can pop it.

    otherwise, the crash time is earlier or even c1 will never crash other later cars, we can ensure that for current car, it will crash c1 only.

    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars)
    {
        int n=cars.size();
        vector<double> ans(n,-1);
        stack<int> s;
        for (int i=n-1; i>=0; --i) {
            while (!s.empty()&&cars[s.top()][1]>=cars[i][1]) s.pop();
            double time=-1;
            while (!s.empty()) {
                time = (double)(cars[s.top()][0]-cars[i][0])/(double)(cars[i][1]-cars[s.top()][1]);
                if (time<=ans[s.top()]||ans[s.top()]==-1) break;
                s.pop();
            }
            ans[i]=time;
            s.push(i);
        }
        return ans;
    }
};
