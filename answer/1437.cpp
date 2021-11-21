class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        if (k==0) return true;
        int i=0, n=nums.size();
        while (i<n&&nums[i]==0) i++;
        while (i<n) {
            int t=i+1;
            while (t<n&&nums[t]==0) t++;
            if (t==n) break;
            if (t-i-1<k) return false;
            i=t;
        }
        return true;
    }
};
