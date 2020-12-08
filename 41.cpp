/***** Fourth Visit *****/
/*
    Ignore non important value, like negative or nums larget than n.
    Otherwise, put it in the correct position.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n=nums.size(), i=0;
        while (i<n) {
            if (nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for (int i=0; i<n; ++i) {
            if (i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};

/***** Third Visit *****/
/*
    the smallest missing positive integer.
    [x,x,x,x,x,x,x]
    We have 7 slots, so the missing positive integer must be in the range of 1 - 8
    First iteration, place the num according to its index
    Second iteration, through over the array and check if idx+1!=num else return length+1.
    T:O(n)/S:O(1)
    -----
    [1,2,3,4]
           ^
    [1,-1,3,4]
          ^
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n=nums.size(); int i=0;
        while (i<n) {
            if (nums[i]>=1&&nums[i]<=n&&nums[i]!=i+1&&nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for (int j=0; j<n; ++j) {
            if (nums[j]!=j+1) return j+1;
        }
        return n+1;
    }
};

/***** Second Visit *****/
/*
    sort then iterative check
    T:O(nlogn)/S:O(1)
    -----
    Now we are asked to have T:O(n)/S:O(1)
    move non-positive num to the end. then check sign bit if exist
    T: 3 pass O(n)/S:O(1)
    -----
    slot filling from 0 - n. Swap the num to the end if overflow.
    T: 2 pass O(n)/S:O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n=nums.size(), i=0;
        while(i<n) {
            if (nums[i]<=0) {swap(nums[i],nums[n-1]); n--;}
            else i++;
        }
        for (int i=0; i<n; ++i) {
            if (abs(nums[i])>n) continue;
            nums[abs(nums[i])-1]=-1*abs(nums[abs(nums[i])-1]);
        }
        // for (int c:nums) cout<<c<<",";
        // cout<<endl;
        for (int i=0; i<n; ++i) {
            if (nums[i]>0) return i+1;
        }
        return n+1;
    }
};

/***** First Visit *****/
// Reduced to Correct Slot Filling
class Solution {
public:
    //T: O(2n), S:O(1)
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;

    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        // T:O(n), S:O(n)
        int min_positive = INT_MAX;
        unordered_set<int> table;
        for (int& num:nums) { //T:O(n)
            if (num>0&&num<min_positive) min_positive = num;
            if (num>0) table.insert(num);
        }
        if (min_positive==INT_MAX||min_positive!=1) return 1;
        int i=2;
        while (i<=table.size()) { //T:O(n)
            if (table.find(i)==table.end()) return i; //T:O(1)
            i++;
        }
        return i;
    }
};
