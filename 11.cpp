class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int i=0; int j=height.size()-1;
        while (i<j) {
            int water = min(height[i],height[j])*(j-i);
            max_water = max(max_water, water);
            if (height[i]<height[j]) i++;
            else j--;
        }
        return max_water;
    }
};
