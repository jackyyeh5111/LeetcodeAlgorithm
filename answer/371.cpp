/***** Third Visit *****/
/*
    3   00011
    -2  11110
        00001
*/
class Solution {
public:
    int getSum(int a, int b)
    {
        bool c=0;
        int ans=0;
        for (int i=0;i<32; ++i) {
            bool x=a&(1<<i), y=b&(1<<i);
            if (x^y^c) ans=ans|(1<<i);
            c=(x&&y)||(x&&c)||(y&&c);
        }
        return ans;
    }
};

/***** Second Visit *****/
class Solution {
public:
    int getSum(int a, int b)
    {
        int ans=0;
        bool c=0;
        for (int i=0; i<32; ++i) {
            bool x=a&(1<<i),y=b&(1<<i);
            ans=ans|((x^y^c)<<i);
            c=(x&y)|(x&c)|(y&c);
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    0110
    0011 +)
    1001

    0110
    1001 +) -> 0110+1=0111
    T:O(32)/S:O(1)

    ref: https://ryanstutorials.net/binary-tutorial/binary-negative-numbers.php
*/
class Solution {
public:
    int getSum(int a, int b) {
        int c=0,ans=0;
        for (int i=0; i<32; ++i) {
            int abit=a&1, bbit=b&1;
            if (abit^bbit^c) ans=ans|(1<<i);
            c=(abit&&bbit)||(abit&&c)||(bbit&&c);
            a>>=1; b>>=1;
        }
        return ans;
    }
};
