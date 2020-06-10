// My soluction: Reduce to convex hull problem and use Graham's Scan Algorithm.
class Solution {
public:
    vector<int> s;
    int trap(vector<int>& height)
    {
        // T:O(n), S:O(n)
        if (height.size()<=2) return 0;

        s.push_back(0); s.push_back(1);
        for (int i=2; i<height.size(); ++i) {
            while (s.size()>1 &&
                   isConcave(height[s[s.size()-2]],height[s[s.size()-1]],height[i])) s.pop_back();
            s.push_back(i);
        }
        for (int c:s) cout<<c<<",";
        cout<<endl;

        int sum=0;
        for (int i=0; i<s.size()-1; ++i) {
            sum+=min(height[s[i]],height[s[i+1]])*(s[i+1]-s[i]-1);
            for (int j=s[i]+1; j<s[i+1]; ++j)
                sum -= height[j];
        }
        return sum;
    }

    bool isConcave(int a, int b, int c)
    {
        if (b<=a&&b<=c) return true;
        else return false;
    }
};

// Two pointers.
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
