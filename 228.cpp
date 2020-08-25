/*
    -----
    Iterative traverse each entry.
    T:O(n), S:O(1)
    -----
    binary search each end point
    best case: T:O(logn)
    worst case: T:O(nlogn)
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {

        int start=0, n=nums.size();
        vector<string> ans;
        while(start<n) {
            int l=start, r=n-1;
            while(l<=r) {
                // cout<<l<<","<<r<<endl;
                int mid=(l+r)/2;
                if ((long)nums[mid]-(long)nums[start]<=(long)mid-(long)start) l=mid+1;
                else r=mid-1;
            }
            if (r==start)
                ans.push_back(to_string(nums[start]));
            else
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[r]));
            start=r+1;
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {

        int i=0, n=nums.size();
        vector<string> ans;
        while(i<n) {
            int l=nums[i], r=l;
            while(i<n-1&&(long)(nums[i]+1)==(long)(nums[i+1])) r=nums[++i];
            string s=to_string(l);
            if (r!=l) {s+="->"+to_string(r);}
            ans.push_back(s);
            i++;
        }
        return ans;
    }
};
