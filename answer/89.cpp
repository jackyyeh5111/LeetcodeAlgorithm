/*
    i ^ i>>1
    0  0000 0000
    1  0001 0001
    2  0010 0011
    3  0011 0010
    4  0100 0110
    5  0101 0111
    T:O(2^n)/S:O(2^n)
*/
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        int k=1<<n;
        for (int i=0; i<k; ++i) {
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    Let's denote i^(i>>1) as f(i). To proof f(i) is the ith gray code, we only need to prove the following statements:

    f(0) = 0
    f(i) and f(i+1) only differs in one digit
    f(i) is bijective, e.g. f(i) = f(j) if and only if i = j.
    The first one is obvious.

    For the second , f(i) ^ f(i+1) = i^(i>>1)^(i+1)^((i+1)>>1) = (i^(i+1)) ^ ((i^(i+1)) >> 1). Let's denote g(i) = i^(i+1), g(i) has the form of 0000111...111. So f(i) ^ f(i+1) = g(i) ^ g(i)>>1 = 00001000...000.

    The third part can be proved alike.
    refers: https://leetcode.com/problems/gray-code/discuss/30028/4-lines-C%2B%2B-code.
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        n=1<<n;
        for (int i=0; i<n; ++i)
            ans.push_back(i^(i>>1));
        return ans;
    }
};

/***** Second Visit *****/
/*
    0 0000
    1 0001 n^(n>>1)
    2 0011
    3 0010
    4 0110
    5 0111
    ...

*/
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans(1,0);
        int t=1<<n;
        for (int i=1; i<t; ++i)
            ans.push_back(i^(i>>1));
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<int> grayCode(int n)
    {
        /*
        3
         0 0 0 /0 1
         0 0 1 /1 2
         0 1 1 /3 3
         0 1 0 /2 4
         1 1 0 /6 5
         1 1 1 /7 6
         1 0 1 /5 7
         1 0 0 /4 8
        */
        // T:O(2^n), S:O(1)
        vector<int> ans; int i=0; int target=(1<<n) - 1;
        while (i<=target) {
            ans.push_back(i^(i>>1));
            ++i;
        }
        return ans;
    }
};
