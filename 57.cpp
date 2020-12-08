/***** Third Visit *****/
/*
    brute force:
    insert then check merge.
    T:2 pass O(logn+n)/S:O(1)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if (n==0) {intervals.push_back(newInterval); return intervals;}
        auto it=lower_bound(intervals.begin(),intervals.end(),newInterval);
        int idx=it-intervals.begin();
        if (idx>0&&intervals[idx-1][1]>=newInterval[0]){
            intervals[idx-1][0]=min(intervals[idx-1][0],newInterval[0]);
            intervals[idx-1][1]=max(intervals[idx-1][1],newInterval[1]);
            idx--;
        }
        else {intervals.insert(it,newInterval); n++;}
        int k=idx+1;
        for (; k<n; ++k) {
            if (intervals[k][0]>intervals[idx][1]) break;
            intervals[idx][1]=max(intervals[k][1],intervals[idx][1]);
        }
        intervals.erase(intervals.begin()+idx+1,intervals.begin()+k);
        return intervals;
    }
};

/***** Second Visit *****/
/*
    1. If they overlap, merge them to newInterval;
    2. If intervals[i] is to the left of newInterval, push intervals[i] to the
        result vector;
    3. If newInterval is to the left of intervals[i], push newInterval and all
       the remaining intervals (intervals[i], ..., intervals[n - 1]) to the
       result vector.
    -----
    find 2 endian interval, say l&r.
    1. sequential push interval[begin~l-1]
    2. push new merged interval with l&r
    3. sequential push interval[r+1~end]
    T:1 pass O(n)S:O(n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> res;
        int n=intervals.size();
        for (int i=0; i<n; ++i) {
            if (intervals[i][1]<newInterval[0])
                res.push_back(intervals[i]);
            else if (intervals[i][0]>newInterval[1]) {
                res.push_back(newInterval);
                for (int j=i; j<n; ++j) res.push_back(intervals[j]);
                return res;
            }
            else newInterval=merge(newInterval,intervals[i]);
        }
        res.push_back(newInterval);
        return res;
    }

    vector<int> merge(vector<int> interval1, vector<int> interval2)
    {
        int start=min(interval1[0],interval2[0]);
        int end=max(interval1[1],interval2[1]);
        return vector<int>{start,end};
    }
};

/***** FIrst Visit *****/
/****************** Not Fix TLE **********************/
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
