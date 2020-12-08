/*
    multiset
    T:O(nklogk*n)/S:O(n)
    -----
    hashmap to record latest index of each num
    T:O(n)/S:O(n)
    -----
    hashmap to record latest k nums appearance
    T:O(n)/S:O(n)
*/

// hashmap to record latest k nums appearance
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        int j=0;
        for (int i=0; i<nums.size(); ++i) {
            if (i-j>k) m[nums[j++]]=max(m[nums[j]]-1,0);
            if (m[nums[i]]>0) return true;
            m[nums[i]]++;
        }
        return false;
    }
};

// hashmap to record latest index of each num
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        for (int i=0; i<nums.size(); ++i) {
            if (m.count(nums[i])!=0&&i-m[nums[i]]<=k)
                return true;
            m[nums[i]]=i;
        }
        return false;
    }
};

// multiset
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        multiset<int> ms;
        int j=0, n=nums.size();
        for (int i=0; i<n; ++i) {
            if (i-j>k&&ms.count(nums[j])) ms.erase(ms.find(nums[j++]));
            if (ms.count(nums[i])) return true;
            ms.insert(nums[i]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        /*
            use a hashmap to record latest appearance index.
            T:O(n) with one pass, S:O(n)
            ---
            Another thought: use unordered_set to keep latest k elements
        */
        unordered_map<int,int> m;
        int size=nums.size();
        for (int i=0; i<size; ++i) {
            int num=nums[i];
            if (m.find(num)!=m.end() && i-m[num]<=k) return true;
            m[num]=i;
        }
        return false;
    }
};
