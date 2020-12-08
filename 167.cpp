/***** Second Visit *****/
/*
    Array:
    1. sort help?
    1-1. bucket sort
    2. binary search
    3. 2 ptr
    4. use a stack to record increasing order.
    5. running ptr
    6. 2-D array
        dp cumuilative solving subproblem, INDUCTION!!
        divide&conquer
        backtracking
        greedy
    -----
    According to the description, there would be only exactly ONE pair.
    Use 2 ptr.
    T:O(n)/S:O(1)
    -----
    Use a hashmap for record visited nums if not sure the pair exist or not.
    T:O(n)/S:O(n)
    -----
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l=0,r=numbers.size()-1;
        vector<int> ans(2,0);
        while (l<r) {
            if (numbers[l]+numbers[r]==target) {
                ans[0]=l+1; ans[1]=r+1;
                return ans;
            }
            else if (numbers[l]+numbers[r]>target) r--;
            else l++;
        }
        return ans; // not going to reach here.
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        /*
            use a set and look backward. One pass
            T:O(n), S:O(n)
            -----------------
            try another approach with S:O(1). 2 ptr?
            2 7 11 15
            ^      ^
            2 7 11 15
            ^   ^
            2 7 11 15
            ^ ^
            T:O(n), S:O(1)
        */
        int l=0, r=numbers.size()-1;
        while(l<r) {
            int sum=numbers[l]+numbers[r];
            if (sum==target) return vector<int>{l+1,r+1};
            else if (sum>target) r--;
            else l++;
        }
        return vector<int>{}; // no solutioin
    }
};
