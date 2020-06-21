class Solution {
public:
    // T: O(n^2)
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        int rows=matrix.size(); int cols=matrix[0].size();
        vector<int> heights(cols,0);
        int maxArea=0;
        for (int row=0; row<rows; ++row) {
            for (int col=0; col<cols; ++col) {
                if (matrix[row][col]=='0') heights[col]=0;
                else heights[col]++;
            }
            int localMax = maxHist(heights);
            maxArea=max(maxArea,localMax);
        }
        return maxArea;
    }

    // T:worst case: O(n)
    int maxHist(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> s;
        int maxRect=0, i=0;

        while(i<heights.size()) {
            if (s.empty()||heights[i]>heights[s.top()]) s.push(i++);
            else {
                int h=heights[s.top()]; s.pop();
                int rect=h * (s.empty() ? i:i-1-s.top());
                maxRect=max(maxRect,rect);
            }
        }
        heights.erase(heights.end()-1);
        return maxRect;
    }
};
