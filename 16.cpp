/***** Second Visit *****/
/*
    Same as 3Sum problem.
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0,diff=INT_MAX;
        for (int i=0; i<n-2; ++i) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                if (sum==target) return target;
                if(abs(sum-target)<diff) {
                    diff=abs(sum-target);
                    ans=sum;
                }
                if (sum>target)r--;
                else l++;
            }
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(N^2), S:O(1)
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest=INT_MAX; int ans;
        for (int i=0; i<nums.size(); ++i) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1; int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                ans = closest > abs(target-sum) ? sum : ans;
                closest = min(closest, abs(target-sum));
                if (sum>target) r--;
                else if (sum<target) l++;
                else return target;
            }
        }
        return ans;

    }
};
