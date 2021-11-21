/***** Third Visit *****/
/*
    multiset with lower_bound checking
    T:O(nlogk)/S:O(n)
    -----
    Bucket sort with size (max-min)/t
    T:O(n)/S:O(n) with 2 pass
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<long> m;
        int j=0, n=nums.size();
        for (int i=0; i<n; ++i)  {
            if (i-j>k) m.erase(m.find(nums[j++]));
            long lower=(long)nums[i]-(long)t, upper=(long)nums[i]+(long)t;
            auto it=m.lower_bound(lower);
            if (it!=m.end()&&*it<=upper) return true;
            m.insert(nums[i]);
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    brute force
    for each num, compare to its +- k neighbors
    T:O(nk)/S:O(1)
    -----
    use a sliding window with size k, data structure: multiset
    for each iteration, use upper_bound to check if exist
    1,5,9,1,5,9    k=2,t=3
    ^ ^ ^
    ^ ^ ^ ^
    ^ ^ ^ ^ ^
      ^ ^ ^ ^ ^
        ^ ^ ^ ^
          ^ ^ ^

    insert/remove: O(logk)
    check duplicate exist: O(logk)
    loop count: n
    T:O(n*(logk+logk))/S:O(k)
    -----
    As first visit, we only need to care latest k elements,
    if size > k, erase(nums[i-k]). Note that we dont need to worry
    multiple erase because if multiple elements exist, we will detect and
    return true first.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (k<0||t<0) return false;
        multiset<long> s;
        int n=nums.size(), m=min(n,k);
        for (int i=0; i<m; ++i) s.insert(nums[i]);
        for (int i=0; i<n; ++i) {
            if (i+k<n) s.insert(nums[i+k]);
            s.erase(s.find(nums[i]));
            if (i>k) s.erase(s.find(nums[i-k-1]));
            if (t==0&&s.find(nums[i])!=s.end()) return true;
            else {
                int dist=distance(s.upper_bound((long)nums[i]-(long)t),s.upper_bound((long)nums[i]+(long)t));
                if (dist>0) return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

/***** First Visit *****/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        /*
            keep track latest k elements and compare each element with
            current value. T:O(nk), worst case: T:O(n^2), S:O(n)
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
