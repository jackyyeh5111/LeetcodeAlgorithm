/***** Fifth Visit *****/
/*
    call by value
    1 2 4 3 3 3 4 5
    1 2 5 3 3 3 4 4
        ^         ^
    T:O(n!)/S:O(n!)
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        dfs(nums,0,ans);
        return ans;
    }

    void dfs(vector<int> nums, int idx, vector<vector<int>> &ans)
    {
        if (idx==nums.size()) {
            ans.push_back(nums);
            return;
        }
        int cur=nums[idx];
        for (int i=idx; i<nums.size(); ++i) {
            if (cur==nums[i]&&i!=idx) continue;
            cur=nums[i];
            swap(nums[i],nums[idx]);
            dfs(nums,idx+1,ans);
        }
    }
};

/***** Fourth Visit *****/
/*
    [1,1,2]

    [1,1,2]
    [1,2,1]
    [2,1,1]
    perm without recover via call by value
    Kind similar to problem 31, Next Permutation.
    Allow strict increasing nums swap only, and perm the rest nums.
    T:O(n!)/S:O(n!)
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        perm(nums,0,ans);
        return ans;
    }

    void perm(vector<int> nums, int idx, vector<vector<int>> &ans)
    {
        int n=nums.size();
        if (idx==n) ans.push_back(nums);
        for (int i=idx; i<n; ++i) {
            if (i!=idx&&nums[idx]>=nums[i]) continue;
            swap(nums[idx],nums[i]);
            perm(nums,idx+1,ans);
        }
    }
};

/***** Third Visit *****/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        perm(nums,0,n,ans);
        return ans;
    }

    void perm(vector<int> &nums, int i, int n, vector<vector<int>> &ans)
    {
        if (i>=n-1) {ans.push_back(nums); return;}
        unordered_set<int> s;
        for (int j=i; j<n; ++j) {
            if (s.count(nums[j])!=0) continue;
            s.insert(nums[j]);
            swap(nums[i],nums[j]);
            perm(nums,i+1,n,ans);
            swap(nums[i],nums[j]);
        }

    }
};

/***** Second Visit ****/
/*
    permutation with duplicate nums and return unique result
    use a set to eliminate all duplicate case.
    Additional cost:T:O(n)/S:O(n)
    Then reduce to normal permutation problem.
    -----
    use a set while swapping numbers, if the number has been swapped before, skip it.
    Additional cost:T:O(n)/S:O(n)
    Then reduce to normal permutation problem.
    -----
    sort first.
    if the two swapping nums with different position are the same, just skip it.
    T:O(n!)/S:O(n!)
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        int n=nums.size();
        help(nums,0,n);
        return ans;
    }

    void help(vector<int>& nums, int idx, int n)
    {
        if (idx>=n) ans.push_back(nums);
        else {
            unordered_set<int> seen;
            for (int i=idx; i<n; ++i) {
                if (seen.count(nums[i])>0) continue;
                seen.insert(nums[i]);
                swap(nums[idx],nums[i]);
                help(nums,idx+1,n);
                swap(nums[idx],nums[i]);
            }
        }
    }
};

/***** First Visit *****/
/*
Making it sorted can only place equal numbers together, so you can skip dup by if(i != pos && nums[i] == nums[pos]) continue;
However, if you use swap twice and passing by reference, the array will not be sorted at some point, for example, 1,2,3,3 when pos = 0 and i = 2, you swap 1 and 3, which means now you have to get permutation of [2,1,3], it's not sorted.

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
