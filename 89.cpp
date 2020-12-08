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
