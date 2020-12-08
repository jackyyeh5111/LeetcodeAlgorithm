/***** Third Visit *****/
/*
    1234567, 3
    7654321
      ^
    5674321
    5671234

    3 times inverse.
    T:O(n)/S:O(1) 3 pass
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

/***** Second Visit *****/
/*
    [1,2,3,4,5,6,7], k=3, n=7
    T:O(n)/S:O(n)
    -----
    brute force:
    T:O(n^2)/S:O(1)
    do k times rotation
    -----
    1 2 3 4 5 6 7
    5 2 3 4 5 6 7, prev=1
    -----
    1 2 3 4, k=2
    3 2 3 4, prev=1, idx=0
    3 2 1 4, prev=3, idx=2

    0 3 6
    1 4 7
    2 5 8
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=nums.size();
        k=k%n;
        if (n<=1||k==0) return;
        int i=0, prev_idx=0, prev=nums[(prev_idx)%n];
        while (i<n) {
            int s=prev_idx;
            do {
                int t=nums[(prev_idx+k)%n];
                nums[(prev_idx+k)%n] = prev;
                prev=t;
                prev_idx=(prev_idx+k)%n;
                i++;
            } while(s!=prev_idx&&i<n);
            prev_idx=(s+1)%n; prev=nums[(prev_idx)%n];
        }
    }
};

/***** First Visit *****/
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
