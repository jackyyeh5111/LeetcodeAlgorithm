/***** Fourth Visit *****/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int l=0,r=height.size()-1,ans=0;
        while(l<=r) {
            ans=max(ans,min(height[l],height[r])*(r-l));
            if (height[l]>=height[r]) r--;
            else l++;
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    2 ptr solution
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int l=0,r=height.size()-1,ans=0;
        while (l<r) {
            ans=max(ans,min(height[l],height[r])*(r-l));
            if (height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    brute force
    enumerate all pair C^n_2 then find max area.
    T:O(n^2)/S:O(1)
    -----
    use 2 ptr!
    greedy select largest bar in left/right endian.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r) {
            int area = (r-l)*min(height[l],height[r]);
            ans=max(ans,area);
            if (height[r]>height[l]) l++;
            else r--;
        }
        return ans;
    }
};

/***** First Visit *****/
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
