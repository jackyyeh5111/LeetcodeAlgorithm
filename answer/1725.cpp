class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) 
    {
        int maxL=INT_MIN, c=0;
        for (auto rect:rectangles) {
            int cmin=min(rect[0],rect[1]);
            if (cmin>maxL) {
                maxL=cmin; c=1;
            }
            else if (cmin==maxL) c++;
        }
        return c;
    }
};