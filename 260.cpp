/*********** Second Visit ***********/
/*
    1
    01
    1
    11  x
    01
    101 x
    ----
    431 -> 011

    bitwise and op can find the unique bit in one of 2 nums which appear
    only once, but we are not sure that which num belongs to this bit.
    Use the bit to separate nums into 2 group. In each group, there are one
    num appears once with lots duplicate nums.
    110 101
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int diff=0;
        for (int num:nums) diff=diff^num;
        // cout<<diff<<endl;
        int delimiter=((diff^(diff-1))+1)>>1;
        // cout<<delimiter<<endl;
        int a=0,b=0;
        for (int num:nums) {
            if (num&delimiter)  a=a^num;
            else b=b^num;
        }
        return vector<int>{a,b};
    }
};

/*********** First Visit ***********/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        /*
            Use a hashmap with T:O(n), S:O(n)
            ------
            T:O(n), S:O(1)
            [1,2,1,5] xor  -> 2 ^ 5 -> 111 = z
            [1^z,2^z,1^z,5^z] -> [1^z,5,1^z,2]

            The 2 num is A,B, find A xor B, which means the different bit between A,B.
            sample one bit then use it to separate the nums into 2 parts. In this time, A,B will
            be separated inito two lists, then reduce to single number problem.
        */
        int c=0;
        for (int num:nums) c=c^num;
        int bit=c&(~(c-1));
        int a=0, b=0;
        for (int num:nums) {
            if (num&bit) a=a^num;
            else b=b^num;
        }
        return vector<int>{a,b};
    }
};
