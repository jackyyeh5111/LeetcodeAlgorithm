/*
    Sample the smallest num, and check if there are k-1 nums after it.
    Greedy find k nums.
    How to check the # of nums remaining?
        use index.
    Which num we should sample if duplicate nums exist?
        sample the small one first.
    -----
    [3,5,2,6]
     0 1 2 3
    -----
    use a hashmap to save each num's index and sorting w.r.t. value as well.
    How to check if there are enough nums remaining?
    How to remove the one we already involved?
    We still need to keep the smaller num even its not ok to be involved at current k/position.
    Sum: hashtable is not a good data structure
    Note that its not good to sample candidate from the smallest.
    -----
    Mono increasing stack

    Use a stacck to save our return subsequence which is the minimal lexicon order we can find so far.
    refers: https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            while (ans.size()!=0&&ans.back()>nums[i]&&n-i-1>=k-ans.size())
                ans.pop_back();
            if (ans.size()<k) ans.push_back(nums[i]);
        }
        return ans;
    }
};
