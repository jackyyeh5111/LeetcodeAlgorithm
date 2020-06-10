class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // do binary search twice to find begin&end, T:O(2logn)
        vector<int> ans;
        int l=0; int r=nums.size()-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (nums[mid]==target&&(mid==0||nums[mid-1]!=target)){
                ans.push_back(mid);
                break;
            }
            else if (nums[mid]<target) l=mid+1;
            else if (nums[mid]>=target) r=mid-1;
        }

        l=0; r=nums.size()-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (nums[mid]==target&&(mid==nums.size()-1||nums[mid+1]!=target)){
                ans.push_back(mid);
                break;
            }
            else if (nums[mid]<=target) l=mid+1;
            else if (nums[mid]>target) r=mid-1;
        }
        if (ans.size()!=2)
            ans = vector<int>{-1,-1};
        return ans;
    }
};
