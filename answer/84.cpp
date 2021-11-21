/***** Fifth Visit *****/
/*
    mono stack!
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);
        // height, idx
        stack<pair<int,int>> s;
        int n=heights.size(), ans=0;
        for (int i=0; i<n; ++i) {
            int idx=i;
            while (!s.empty()&&s.top().first>heights[i]) {
                auto p=s.top(); s.pop();
                ans=max(ans,p.first*(i-p.second));
                idx=p.second;
            }
            s.push({heights[i],idx});
        }
        return ans;
    }
};

/***** Fourth Visit *****/
/*
    mono sack
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<pair<int,int>> s; //idx, h
        heights.push_back(0);
        int n=heights.size(),ans=0;
        for (int i=0; i<n; ++i) {
            int t=i;
            while (!s.empty()&&s.top().second>=heights[i]) {
                auto p=s.top(); s.pop();
                ans=max(ans,p.second*(i-p.first));
                t=p.first;
            }
            s.push({t, heights[i]});
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    Use a stack to store increasing order with <pos, height>
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size(), ans=0;
        stack<pair<int,int>> s;
        for (int i=0; i<n; ++i) {
            int minpos=INT_MAX;
            while(!s.empty()&&s.top().second>heights[i]) {
                auto p=s.top(); s.pop();
                ans=max(ans,p.second*(i-p.first));
                minpos=min(minpos,p.first);
            }
            if (minpos!=INT_MAX) s.push({minpos,heights[i]});
            s.push({i,heights[i]});
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    Array:
    1. could sort help? could bucket sort help?
    2. could binary search help?
    3. 2 ptr, start/end
    4. running ptr
    5. 2-D: DP/greedy/divide&conquer
    -----
    3 3 5 6 2 3
    2 2 5 2 2 3
    -----
    0 4 5 1 2 3 0
    s: 01
    -----
    the bottom of stack means the minimum num in the array so far.
    Within the iteration, we check each larger bar to current(running) ptr,
    and find max area so far BACKWARD, not forward.
    In the end, we need to check the area with min heigh so far to current ptr.
    Add dummy 0 to clear the stack at the end, i.e. sanity checking
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);
        stack<int> s;
        int l=0, ans=0, n=heights.size();
        while (l<n) {
            if (s.empty()||heights[s.top()]<heights[l]) {
                s.push(l++);
            }
            else {
                int height=heights[s.top()]; s.pop();
                ans=max(ans,height*(s.empty()?l:l-s.top()-1));
            }
        }
        return ans;
    }
};

/***** First Visit *****/
/*
For any bar i the maximum rectangle is of width r - l - 1 where
  r - is the last coordinate of the bar to the right with height h[r] >= h[i]
  l - is the last coordinate of the bar to the left which height h[l] >= h[i]

use a stack to save the index of each vector entry in a ascending order; once the current entry is smaller than the one with the index s.top(), then that means the rectangle with the height height[s.top()] ends at the current position, so calculate its area and update the maximum.
Add dummy 0 to clear the stack at the end, i.e. sanity checking
*/
class Solution {
public:
    // brute force: T:O(n^3)
    //   2 ptrs to find all compare, and 1 iterative find local min
    // divide & conquer. T:O(n), eliminate the time for searching local min.
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);
        stack<int> s;
        int i=0; int largest=0;
        while (i<heights.size()) {
            // save idx of acending order
            if (s.empty()||heights[s.top()]<heights[i]) s.push(i++);
            // met a smaller bar, means height[s.top] could reach up to i.
            // keep compare and update largest
            else {
                int curIdx = s.top(); s.pop();
                int height = heights[curIdx];
                largest = max(largest,height*(s.empty()?i:i-1-s.top()));
            }
        }
        return largest;
    }
};
/*
[1,2,3,4,5]
[2,1,5,6,2,3]
[3,5,2,10,10,1]
[2,6,6,10,10,1]
[3,4,5,6,7,8,20,30]
[2,6,6,10,1000,1]
[3]
[]
[2,3,4,]
*/
