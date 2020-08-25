class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        /*
            [2,5,6,8,12,15]
            [1,2,6,10,15]
            T:O(n),S:O(1)
            Actually this can be reduce to 1 pass solution.
            for (int i=0 to size) {
                while sum>s check ans.
            }
            -------------
            T:O(nlogn)
            1 pass: Accumulate num computation
            2 pass: binary search for each element to find min boundary. Thus
                    time computation would be n*O(logn)
        */
        int sum=0; nums.insert(nums.begin(),0); // add sanity check
        for (int &num:nums) {sum+=num; num=sum;}
        int l=0,r=0,n=nums.size();
        int ans=INT_MAX;
        while (l<=r&&r<n) {
            int diff=nums[r]-nums[l];
            if (diff<s) r++;
            else {
                ans=min(ans,r-l);
                l++;
            }
        }
        if (ans==INT_MAX) return 0;
        else return ans;
    }
};
