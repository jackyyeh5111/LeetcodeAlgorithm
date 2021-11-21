/*
    cached DP
    Bottom-up DP + Recursive
    plan(i) is the cost to fulfill the travel plan from day i to the end.
    T:O(365)/S:O(365)
    ---------
    Top down DP
    T:O(365)/S:O(365)
*/

/********* cached DP with recursive *********/
class Solution {
public:
    vector<int> table;
    unordered_set<int> s;
    vector<int> costs;
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        table=vector<int>(366,-1);
        s=unordered_set<int>(days.begin(),days.end());
        this->costs=costs;
        return plan(1);
    }

    int plan(int day)
    {
        if (day>365) return 0;
        else if (table[day]>=0) return table[day];
        int ans=0;
        if (s.find(day)!=s.end()) {
            ans=min(costs[0]+plan(day+1),min(costs[1]+plan(day+7),costs[2]+plan(day+30)));
        }
        else ans=plan(day+1);
        table[day]=ans;
        return ans;
    }
};

/********* cached DP with recursive *********/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> table(366);
        unordered_set<int> s(days.begin(),days.end());
        for (int i=1; i<366; ++i) {
            if (s.find(i)==s.end()) table[i]=table[i-1];
            else {
                table[i]=min(costs[0]+table[i-1],
                    min(costs[1]+table[max(0,i-7)],
                        costs[2]+table[max(0,i-30)])
                );
            }
        }
        return table[365];
    }
};
