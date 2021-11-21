/*
    2/4 3/4  extra:4
    4/8 7/8 -> 11
    6/8 6/8 -> 12
    Use priority queue.
    
    T:O(nlogm)/S:O(m)
*/

// array and cumulative probability.
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<pair<double,array<int,2>>> pq;
        double ans=0;
        for (auto &cls:classes) {
            pq.push({profit(cls[0],cls[1]),{cls[0],cls[1]}});
            ans+=(double)cls[0]/(double)cls[1];
        }
        for (int i=0; i<extraStudents; ++i) {
            auto t=pq.top(); pq.pop();
            ans+=t.first;
            t.second[0]+=1; t.second[1]+=1;
            pq.push({profit(t.second[0],t.second[1]),t.second});
        }
        return ans/(double)classes.size();
    }

    double profit(double pass, double total)
    {
        return (pass+1)/(total+1)-pass/total;
    }
};

// TLE: vector costs time!! use array instead.
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        auto compare = [](vector<int> &a, vector<int> &b) {
            double aOld=(double)a[0]/(double)a[1];
            double aNew=(double)(a[0]+1)/(double)(a[1]+1);
            double bOld=(double)b[0]/(double)b[1];
            double bNew=(double)(b[0]+1)/(double)(b[1]+1);
            return aNew-aOld<=bNew-bOld;
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(compare)> pq(compare);
        double ans=0; double n=0;
        for (auto &cls:classes) {
            if (cls[0]==cls[1]) ans+=1;
            else pq.push(cls);
            n++;
        }
        if (!pq.empty()) {
            for (int i=0; i<extraStudents; ++i) {
                auto t=pq.top(); pq.pop();
                t[0]+=1; t[1]+=1;
                pq.push(t);
            }
            while (!pq.empty()) {
                auto t=pq.top(); pq.pop();
                ans+=(double)t[0]/(double)t[1];
            }
        }

        return ans/n;
    }
};
