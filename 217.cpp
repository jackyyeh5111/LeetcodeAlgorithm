/***** Third Visit *****/
/*
    sort T:O(nlogn)/S:O(1)
    unordered_set T:O(n)/S:O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> us;
        for (int num:nums) {
            if (us.count(num)) return true;
            us.insert(num);
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    brute force: T:O(n^2)/S:O(1) enumerate all pairs
    -----
    use a hashset to check if duplicate T:O(n)/S:O(n)
    -----
    sort in-place and compare T:O(nlogn)/S:O(1)
    -----
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
        for (int num:nums) {
            if (s.count(num)!=0) return true;
            s.insert(num);
        }
        return false;
    }
};

/***** First Visit *****/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> m;
        for (int num:nums) {
            if(m.find(num)!=m.end()) return true;
            m.insert(num);
        }
        return false;
    }
};
