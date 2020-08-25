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
