class Solution {
public:
    vector<int> partitionLabels(string s) {
        // step 1: creae hashmap
        unordered_map<int, pair<int, int>> hashmap;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (hashmap.count(ch))
                hashmap[ch].second = i;
            else 
                hashmap[ch] = make_pair(i, i);
        }
        
        // create intervals
        vector<pair<int, int>> intervals;
        for (const auto &entry : hashmap)
            intervals.push_back(entry.second);
        
        if (intervals.size() == 1)
            return {intervals[0].second - intervals[0].first + 1};

        // 2) sort intervals by end value
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        };
        sort(intervals.begin(), intervals.end(), comp);

        // 3) combine overlapped intervals   
        /* 
            -----
              _ 
                   ---
         */
        vector<int> ans;
        int start = 0;
        int end = intervals[0].second;
        for(int i = 0; i < intervals.size() - 1; i++) {
            int next_start = intervals[i+1].first;
            int next_end = intervals[i+1].second;
            if (end >= next_start)
                end = max(end, next_end);
            else {
                ans.push_back(end - start + 1);
                start = next_start;
                end = next_end;
            }
        }

        // 4) check last interval
        /* 
            -----
              _ 
                   ---
         */
        int N = intervals.size();
        if (start <= intervals[N - 2].second) {
            end = max(end, intervals[N - 1].second);
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};

/* 
    1) create hashmap
    2) sort intervals
    3) combine overlapped intervals

    hashmap
    {
        a: [0, 4]
        b: [1, 1]
        c: [3, 5]
    }
    abacacd
    -----
     _ 
       ---
    +1
           -

    1) aa b c
 */