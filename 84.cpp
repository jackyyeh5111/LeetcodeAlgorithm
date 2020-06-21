/*
For any bar i the maximum rectangle is of width r - l - 1 where r - is the last coordinate of the bar to the right with height h[r] >= h[i] and l - is the last coordinate of the bar to the left which height h[l] >= h[i]

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
