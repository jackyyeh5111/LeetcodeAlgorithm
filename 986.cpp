class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int first = 0, second = 0;
        while(first < firstList.size() && second < secondList.size()) {
            // specify next
            int start = max(firstList[first][0], secondList[second][0]);
            int end = min(firstList[first][1], secondList[second][1]);
            
            // check intersection
            if (start <= end)
                ans.push_back({start, end});
            
            // update end
            if (firstList[first][1] < secondList[second][1])
                first++;
            else
                second++;
        }
        return ans;
    }
};

/* 
    Approach 1: brute force
        1. merge two lists into a new list C
        2. for loop list C 
 
    Approach 2: two pointers for two sequences
        1. keep track of the farthest end


    ____________________
       __ __ __ 
 */         