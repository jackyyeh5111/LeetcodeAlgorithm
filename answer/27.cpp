/***** Third Visit *****/
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int p=0,n=nums.size();
        for (int i=0; i<n; ++i) {
            if (nums[i]!=val) swap(nums[i],nums[p++]);
        }
        return p;
    }
};

/***** Second Visit *****/
/*
    Array:
    1. First think about 2 ptr solution.
    Use a running ptr to check the num which is not val, and another ptr to restore
    non-val num.
    T:O(n)/S:O(1)
    -----
    if we have few duplicated nums, swap the duplicate one to the end
    instead.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i=0,n=nums.size();
        while (i<n) {
            if (nums[i]==val) nums[i]=nums[--n];
            else i++;
        }
        return n;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i=0,n=nums.size();
        for (int j=0; j<n; ++j) {
            if (nums[j]!=val) swap(nums[i++],nums[j]);
        }
        return i;
    }
};

/***** First Visit *****/
/************** If most entries are duplicated *************/
/*
Since this question is asking us to remove all elements of the given value in-place, we have to handle it with O(1)O(1) extra space. How to solve it? We can keep two pointers ii and jj, where ii is the slow-runner while jj is the fast-runner.
*/
class Solution {
public:
    // T:O(2n), S:O(1)
    int removeElement(vector<int>& nums, int val)
    {
        int i=0;
        for (int j=0; j<nums.size(); ++j) {
            if (nums[j]!=val) {
                nums[i++]=nums[j];
            }
        }
        return i;
    }
};

/************** If most entries are NOT duplicated *************/
/*
Now consider cases where the array contains few elements to remove. For example, nums = [1,2,3,5,4], val = 4nums=[1,2,3,5,4],val=4. The previous algorithm will do unnecessary copy operation of the first four elements. Another example is nums = [4,1,2,3,5], val = 4nums=[4,1,2,3,5],val=4. It seems unnecessary to move elements [1,2,3,5][1,2,3,5] one step left as the problem description mentions that the order of elements could be changed.
*/
class Solution {
public:
    // T:O(n), S:O(1)
    int removeElement(vector<int>& nums, int val)
    {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
