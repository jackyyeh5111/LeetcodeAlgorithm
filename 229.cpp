/***** Third Visit *****/
/*
    Appear more than ⌊ n/3 ⌋ times which means we have at most 2 answers.
    Apply Boyer-Moore Voting as well.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int c1=0,c2=0,a=0,b=0;
        for (int num:nums) {
            if (a==num) c1++;
            else if (b==num) c2++;
            else if (c1==0) {a=num; c1=1;}
            else if (c2==0) {b=num; c2=1;}
            else {c1--; c2--;}
        }
        vector<int> ans;
        c1=0; c2=0;
        for(int num:nums) {
            if (num==a) c1++;
            if (num==b) c2++;
        }
        if (c1>nums.size()/3) ans.push_back(a);
        if (c2>nums.size()/3&&a!=b) ans.push_back(b);
        return ans;
    }
};

/***** Second Visit *****/
/*
    brute force:
    use a hashmap, k: num, c: appear times, and traverse over all nums.
    T:O(n)/S:O(n)
    -----
    check the appearance of each num with constant space
    T:O(n^2)/S:O(1)
    -----
    sort
    T:O(nlogn)/S:O(1)
    -----
    MORE THAN ⌊ n/3 ⌋ majority num. There are at most TWO majority nums.
    Treat it as 2 separate majority num check.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int a=0,b=0,ca=0,cb=0;
        for (int num:nums) {
            if (a==num) ca++;
            else if (b==num) cb++;
            else if (ca==0) {a=num; ca=1;}
            else if (cb==0) {b=num; cb=1;}
            else {ca--; cb--;}
        }
        vector<int> ans;
        int t=nums.size()/3;
        ca=0, cb=0;
        for (int num:nums) {ca+=(num==a); cb+=(num==b);}
        if (ca>t) ans.push_back(a);
        if (cb>t&&a!=b) ans.push_back(b);
        return ans;
    }
};

/***** First Visit *****/
/*
    we can apply hashmap with T:O(n), S:O(n)
    --------------
    apply sorting T:O(nlogn), S:O(1)
    --------------
    [1,1,1,3,3,2,2,2] n=8
    -> at least appear 3 times
    -> find duplicate in 2 bins
    -> how to find duplicate in S:O(1)?
    --------------
    Boyer-Moore Majority vote
    "all elements that appear more than ⌊ n/3 ⌋ times." means at most 2
    answer.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> ans;
        int c1=0, c2=0, a=0, b=0;
        for (int num:nums) {
            if (num==a) c1++;
            else if (num==b) c2++;
            else if (c1==0) {a=num; c1++;}
            else if (c2==0) {b=num; c2++;}
            else {c1--; c2--;}
        }
        int target=nums.size()/3;
        if (count(nums.begin(), nums.end(), a)>target)
            ans.push_back(a);
        if (a!=b&&count(nums.begin(), nums.end(), b)>target)
            ans.push_back(b);
        return ans;
    }
};
