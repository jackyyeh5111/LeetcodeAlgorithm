/*
    top-down stack approach.
    We use stack to record current 3, 2 val. If we meet a larger incoming num, the num on the top of stack becomes 2. Thus we will have all valid 3,2 pair.
    We can check thee incoming num if its the smallest one, i.e. 1.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        int mid=INT_MIN;
        stack<int> s;
        for (int i=n-1; i>=0; --i) {
            if (mid>nums[i]) return true;
            while (!s.empty()&&nums[i]>s.top()) {
                mid=s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

/*
    brute force:
    For each position k, find all pairs in the range of 0 - k-1 and see if 132 pattern
        in (nums[i],nums[j],nums[k]) where i<j<k
        T:O(n^3)/S:O(1)
    -----
    ARG sort and use a set to record if we've met or not.
    The domain of num will reduce to 1 ~ n
    T:O(nlogn)/S:O(n)
    [3,5,0,3,4]
    [2,5,1,3,4]
    -----
    Use a stack to record ascending order and a local min.
    See if the incoming num is in the range of [local min, s.top()]
    T:O(n)/S:O(n)
    FAIL case: [3,5,0,3,4]
    -----
    AC, record every ascending region and binary search on these regions
    T(n) = log1 + ... + log(n/2) = O(nlogn)
    S: O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        if (n<=2) return false;
        set<vector<int>> regions;
        vector<int> region{nums[0],nums[0]};
        auto cmp = [](int val, auto r){
            return r[0]<val;
        };
        auto cmp2 = [](auto r, int val){
            return r[1]<val;
        };
        for (int i=1; i<n; ++i) {
            if (nums[i]>=region[1]) region[1]=nums[i];
            else {
                if (region[0]<region[1]) regions.insert(region);
                region[0]=region[1]=nums[i];
            }
            auto it=upper_bound(regions.begin(),regions.end(),nums[i],cmp);
            if(it!=regions.end()) it=next(it,1);
            it=lower_bound(regions.begin(),it,nums[i],cmp2);
            if (it!=regions.end()&&nums[i]<(*it)[1]&&nums[i]>(*it)[0])
                return true;
        }
        return false;
    }
};
