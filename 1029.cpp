class Solution {
public:
    // T:O(nlogn)
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        vector<pair<int,int>> failure;
        for (int i=0; i<costs.size(); ++i)
            failure.push_back(make_pair(costs[i][1]-costs[i][0],i));
        sort(failure.begin(), failure.end(), [](auto& x, auto& y){
            return x.first<=y.first;
        });
        int sum=0;
        for (int i=0; i<costs.size()/2; ++i) {
            sum += costs[failure[i].second][1];
            sum += costs[failure[costs.size()-1-i].second][0];
        }
        return sum;
    }
};
