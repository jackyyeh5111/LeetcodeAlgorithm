/***** Fourth Visit *****/
/*
    Binary search on >= and >.
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // first >=
        int lb=0,r=nums.size();
        while (lb<r) {
            int mid=(lb+r)/2;
            if (nums[mid]>=target) r=mid;
            else lb=mid+1;
        }

        // first >
        int ub=0; r=nums.size();
        while (ub<r) {
            int mid=(ub+r)/2;
            if (nums[mid]>target) r=mid;
            else ub=mid+1;
        }
        if (lb==ub) return {-1,-1};
        else return {lb,ub-1};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto lb=lower_bound(nums.begin(),nums.end(),target); // >=target
        auto ub=upper_bound(nums.begin(),nums.end(),target); // > target
        if (lb==ub) return {-1,-1};
        else return {(int)(lb-nums.begin()),(int)(ub-nums.begin())-1};
    }
};

/***** Third Visit *****/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size();
        while (l<r) {
            int mid=(l+r)/2;
            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (l==nums.size()||l<0||nums[l]!=target)
            return {-1,-1};
        vector<int> ans={l};
        l=0,r=nums.size();
        while (l<r) {
            int mid=(l+r)/2;
            if (nums[mid]>target) r=mid;
            else l=mid+1;
        }
        ans.push_back(l-1);
        return ans;
    }
};

/***** Second Visit *****/
/*
    Array
    1. 2 ptr solution
    2. binary search
    3. moving window
    we are asked to have T:O(logn), thus we could think binary search first.
    Do two binary search!!
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans;
        int n=nums.size();
        int l=0,r=n;
        if (r==0) return vector<int>{-1,-1};
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if (l>=n||nums[l]!=target) return vector<int>{-1,-1};
        ans.push_back(l);
        r=nums.size();
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]!=target) r=mid;
            else l=mid+1;
        }
        ans.push_back(l-1);
        return ans;
    }
};

/***** First Visit *****/
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
