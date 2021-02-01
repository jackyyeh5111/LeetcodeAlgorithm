/***** Third Visit *****/
/*
    Reduce to problem 84.
    T:O(mn)/S:O(n)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<int> table(n+1,0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]=='1') table[j]++;
                else table[j]=0;
            }
            ans=max(ans,maxRect(table));
        }
        return ans;
    }

    int maxRect(const vector<int> &table)
    {
        stack<pair<int,int>> s;
        int n=table.size(), ret=0;
        for (int i=0; i<n; ++i) {
            int minPos=INT_MAX;
            while (!s.empty()&&s.top().second>table[i]) {
                auto p=s.top(); s.pop();
                ret=max(ret,p.second*(i-p.first));
                minPos=min(minPos,p.first);
            }
            if (minPos!=INT_MAX) s.push({minPos,table[i]});
            s.push({i,table[i]});
        }
        return ret;
    }
};

/***** Second Visit (Fail) *****/
/*
    1 2 4 4 4 6 1 0
  s:            6
    Same as problem 84.
    while finding max area so far, look backward instead of forward.
    Considering duplicated cases, we will only record the max idx and look
    backward.
    Also add 0 sanity check.
    T:O(mn)/S:O(n)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size(),ans=0;
        vector<int> heights(n,0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]=='0') heights[j]=0;
                else heights[j]++;
            }
            ans=max(ans,maxArea(heights));
        }
        return ans;
    }

    int maxArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> s;
        int n=heights.size(),ret=0,i=0;
        while (i<n) {
            if (s.empty()||heights[s.top()]<heights[i]) s.push(i++);
            else {
                int t=s.top(); s.pop();
                ret=max(ret,heights[t]*(s.empty()?i:(i-s.top()-1)));
            }
        }
        heights.pop_back();
        return ret;
    }
};

/***** First Visit *****/
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
