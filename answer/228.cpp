/***** Second Visit *****/
/*
    sorted unique list -> BINARY SEARCH
    TC worst: log(n-1)+...+log(1)=O(nlogn)
    TC best: O(logn)
    SC O(1)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> v;
        int n=nums.size(),i=0;
        while (i<n) {
            int l=i,r=n;
            // l would be thee minimal index which doesnt satisfy the condition.
            while (l<r) {
                int mid=(l+r)/2;
                if (((long)nums[mid]-(long)nums[i])==(mid-i)) l=mid+1;
                else r=mid;
            }
            if (i==l-1) v.push_back(to_string(nums[i]));
            else v.push_back(to_string(nums[i])+"->"+to_string(nums[l-1]));
            i=l;
        }
        return v;
    }
};

/*
    naiive linear approach
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> v;
        int i=0, n=nums.size();
        while (i<n) {
            int j=i;
            while (j<n-1&&nums[j+1]==nums[j]+1) j++;
            if (i!=j) v.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            else v.push_back(to_string(nums[i]));
            i=j+1;
        }
        return v;
    }
};

/***** First Visit *****/
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
