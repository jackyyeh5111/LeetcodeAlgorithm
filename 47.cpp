/*
Making it sorted can only place equal numbers together, so you can skip dup by if(i != pos && nums[i] == nums[pos]) continue;
However, if you use swap twice and passing by reference, the array will not be sorted at some point, for example, 1,2,3,3 when pos = 0 and i = 2, you swap 1 and 3, which means now you have to get permutation of [2,1,3], it's not sorted.

Thanks for the explanation! I finally figured it out.

Yes, the reason of sorting is to skip duplicates. Take [1, 2, 2, 3] for example, when pos equals 0, we have below cases

(1,2,2,3) (pos = 0, i = 0)

(2,1,2,3) (pos = 0, i = 1)

(2,1,2,3) (pos = 0, i =2) skipped, since array[0]=array[2]; in other words, its subset (1,2,3) is the same as the second case (pos = 0, i=1)

(3,1,2,2) (pos = 0, i =3)

As we can see, the subset of the above four cases are still sorted. Amazing! Recursion continues.

On the other hand, if we use pass-by-reference, the set are ALWAYS sorted AFTER the extra swap, as below. The above amazing trick doesn’t work and duplicates won’t be avoided. So, the result of pass-by-reference algorithm is not correct.
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        // T:O(n!*n)
        sort(nums.begin(),nums.end());
        permuteUnique(nums, 0);
        return ans;
    }

    void permuteUnique(vector<int> nums, int start)
    {
        if (start==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        // unordered_set<int> s;
        for (int i=start; i<nums.size(); ++i) {
            if (i!=start&&nums[i]==nums[start]) continue;
            swap(nums[start], nums[i]);
            permuteUnique(nums, start+1);
            // swap(perm[start], perm[i]);
        }
    }
};

/*
create a hashtable to record which number has swapped , then we can pass nums by reference
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        // T:O(n!*n)
        vector<int> perm = nums;
        permuteUnique(nums, 0, perm);
        return ans;
    }

    void permuteUnique(vector<int>& nums, int start, vector<int>& perm)
    {
        if (start==nums.size()-1){
            ans.push_back(perm);
            return;
        }
        unordered_set<int> s;
        for (int i=start; i<nums.size(); ++i) {
            if (s.find(perm[i])!=s.end()) continue;
            s.insert(perm[i]);
            swap(perm[start], perm[i]);
            permuteUnique(nums, start+1, perm);
            swap(perm[start], perm[i]);
        }
    }
};
