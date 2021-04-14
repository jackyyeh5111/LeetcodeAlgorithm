/***** Second Visit *****/
/*
    The below code will fail in this case:
    [3,15] [6,20] [8,9] [16,17] [18,19]
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            if (a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        });
        int ans=0, n=intervals.size(), i=0;
        while (i<n)
            int end=intervals[i][1], j=i+1, rooms=0;
            while(j<n&&intervals[j][0]<end) {rooms++; j++;}
            ans=max(ans,rooms);
        }
        return ans;
    }
};
/***** First Visit *****/
/*
    counting all overlay regions
    -----
    considering the max overlay region at a time x, find the maximum x.
    Maintain a min queue to record each end time of meetings.
    While we iterate over the schedule in ascending order, pop out the end meeting by comparing min num in q and the start time, i.e. current time, of the interval we are looking at.
    T:O(nlogn)/S:O(n)
    -----
    Treat it as lanndscape problem
    +: means we are going up -> start the meeting
    -: means we are going down -> end the meeting
    find the max accumulate sum which denotes the max rooms we need
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            if (a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        });
        int ans=0, n=intervals.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto t:intervals) {
            while (!pq.empty()&&pq.top()<=t[0]) pq.pop();
            pq.push(t[1]);
            ans=max(ans,(int)pq.size());
        }
        return ans;
    }
};

class Solution {
public:
    int minMeetingRooms(vector& intervals)
    {
        map<int, int> mp; // key: time; val: +1 if start, -1 if end
        for(int i=0; i< intervals.size(); i++) {
            mp[intervals[i].start] ++;
            mp[intervals[i].end] --;
        }
        int cnt = 0, maxCnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cnt += it->second;
            maxCnt = max( cnt, maxCnt);
        }
        return maxCnt;
    }
};
