class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        /*
            S:O(1) T:O(n)
            bottom up k elements, pop_back and insert in the begining
            cons: overhead whiel moving array
            -----------------
            S:O(n), create a new array and move each element in the right position
            T:O(n)
            -----------------
            reverse
        */
        k=k%nums.size(); // ensure TLE
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        /*
            S:O(1) T:O(n)
            bottom up k elements, pop_back and insert in the begining
            cons: overhead whiel moving array
            -----------------
            S:O(n), create a new array and move each element in the right position
            T:O(n)
            -----------------
            reverse
        */
        k=k%nums.size(); // ensure TLE
        for (int i=0; i<k; ++i) {
            int back=nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),back);
        }
    }
};
