class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> lefts(N), rights(N); // dp array
        
        // init left, right
        lefts[0] = height[0];
        for (int i = 1; i < N; i++)
            lefts[i] = max(height[i], lefts[i-1]);
        rights[N-1] = height[N-1];
        for (int i = N - 2; i >= 0; i--)
            rights[i] = max(height[i], rights[i+1]);

        int ans = 0;
        for (int i = 1; i < N - 1; i++) {
            ans += min(lefts[i], rights[i]) - height[i];
        }
        return ans;
    }
};

/* 

           1 2 1 3
     left: 1 2 2 3 
    right: 3 3 3 3
 */