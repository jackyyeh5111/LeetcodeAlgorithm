/***** Second Visit *****/
/*
    use accending cumulation cur and binary search on the num smaller than cur-s
    Add 0 in the front for sanity check on exactly total_sum==s
    T:O(nlogn)/S:O(n)
    -----
    2 ptr solution, greedy find each region that sum up larger than s.
    T:O(n)/S:O(1)
    -----
    Follow-up:
    If the num could be negative integer, could our algo still work?
    If not, what's the optimized time complexity?

    refer: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        nums.insert(nums.begin(),0);
        int cur=0, n=nums.size(), ans=INT_MAX;
        for (int i=0; i<n; ++i) {
            cur+=nums[i];
            nums[i]=cur;
            int l=0, r=i+1;
            while (l<r) {
                int mid=(l+r)/2;
                if (nums[mid]>cur-s) r=mid;
                else l=mid+1;
            }
            if (l>0) ans=min(ans,i-l+1);
        }
        return ans==INT_MAX?0:ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0, r=0, n=nums.size(), cur=0, ans=INT_MAX;
        while (r<n) {
            while (r<n&&cur<s) cur+=nums[r++];
            while (l<r&&cur-nums[l]>=s) cur-=nums[l++];
            if (cur>=s) ans=min(ans,r-l);
            cur-=nums[l++];
        }
        return ans==INT_MAX?0:ans;
    }
};

/***** First Visit *****/
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
