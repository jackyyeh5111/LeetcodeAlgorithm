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
