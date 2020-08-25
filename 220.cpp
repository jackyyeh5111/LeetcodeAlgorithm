class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        /*
            keep track latest k elements and compare each element with current
            value. T:O(nk), worst case: T:O(n^2), S:O(n)
            ----------------
            try to reduce to T:O(n), S:O(n)
            accumulate?
            [1,2,3,4,5]  2 4
            ----------------
            use a set to track latest k elements and upper/lower bound
            ** Actually we just need to find lower bound. **
        */
        if (t<0||k<0) return false;
        set<long> s;
        for (int i=0; i<nums.size(); ++i) {
            // for (auto it=s.begin();it!=s.end();++it) cout<<*it<<"..";
            // cout<<";";
            if (s.size()>k) s.erase(nums[i-s.size()]);
            if (s.size()>0){
                auto lt=s.lower_bound((long)nums[i]-(long)t);
                auto ut=s.upper_bound((long)nums[i]+(long)t);
                // cout<<*lt<<","<<*ut<<endl;
                if ((lt!=s.end()||ut!=s.end())&&distance(lt,ut)>=1)
                    return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
