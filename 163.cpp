/*
    sort
    T:O(nlogn)/S:O(n)
    -----
    Actually the given nums array is in ascending order.
    Thus we only need to add sanity check in the begining and the end.
    T:2 pass O(n)/S:O(1)
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> ans;
        nums.insert(nums.begin(),lower-1);
        int n=nums.size();
        nums.push_back(upper+1);
        for (int i=0; i<n; ++i) {
            int l=max(nums[i],lower-1), r=nums[i+1];
            if (r-l==2) ans.push_back(to_string(l+1));
            else if (r-l>2) ans.push_back(to_string(l+1)+"->"+to_string(r-1));
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        nums.push_back(lower-1);
        nums.push_back(upper+1);
        sort(nums.begin(),nums.end());
        vector<string> ans;
        int n=nums.size();
        for (int i=0; i<n-1; ++i) {
            if (nums[i]<lower-1) continue;
            else if (nums[i]>upper) break;
            int r=nums[i+1], l=nums[i];
            if (r-l==2) ans.push_back(to_string(l+1));
            else if (r-l>2) ans.push_back(to_string(l+1)+"->"+to_string(r-1));
        }
        return ans;
    }
};
