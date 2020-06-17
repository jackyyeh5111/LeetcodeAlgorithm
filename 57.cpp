/****************** Fix TLE **********************/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        // use binary search to find out proper inset position, say idx, T:O(logn)
        // check if newInterval[0]<= intervals[idx-1][1], then merge
        // iteratively check merge from i, T:O(n)
        int l=0; int r=intervals.size()-1; int idx=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if (intervals[mid][0]==newInterval[0]) {
                idx = mid+1;
                break;
            }
            else if (intervals[mid][0]>newInterval[0]) r=mid-1;
            else  l=mid+1;
        }
        if (idx==-1) idx=l;
        intervals.insert(intervals.begin()+idx, newInterval);
        // case1: idx==0
        // case2: idx==n-1
        // case3: 0<idx<n-1
        int i=max(idx-1,0);
        while(i<intervals.size()-1) {
            // cout<<intervals[i][0]<<","<<intervals[i][1]<<endl;
            if (intervals[i+1][0]<=intervals[i][1]) {
                //merge
                intervals[i][1]=max(intervals[i+1][1],intervals[i][1]);
                intervals.erase(intervals.begin()+i+1);
            }
            else i++;
        }
        return intervals;
    }
};

/****************** Fix TLE **********************/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        // use binary search to find out proper inset position, say idx, T:O(logn)
        // check if newInterval[0]<= intervals[idx-1][1], then merge
        // iteratively check merge from i, T:O(n)
        int l=0; int r=intervals.size()-1; int idx=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if (intervals[mid][0]==newInterval[0]) {
                idx = mid+1;
                break;
            }
            else if (intervals[mid][0]>newInterval[0]) r=mid-1;
            else  l=mid+1;
        }
        if (idx==-1) idx=l;
        if (idx>0 && (intervals[idx-1][1]>=newInterval[0])) {
            intervals[idx-1][1] = max(intervals[idx-1][1],newInterval[1]);
            idx--;
        }
        else intervals.insert(intervals.begin()+idx, newInterval);
        int start=idx;
        for (int i=start; i<intervals.size()-1; ++i) {
            if (intervals[i+1][0]>intervals[start][1]) break;
            while(i<intervals.size()-1&&intervals[i+1][0]<=intervals[start][1]) i++;
            intervals[start][1]=max(intervals[i][1],intervals[start][1]);
            intervals.erase(intervals.begin()+start+1, intervals.begin()+i+1);
        }

        return intervals;
    }
};
