/***** Fourth Visit *****/
/*
    0101 5
    0110 6
    0111 7
    find how many bits we are going to modify to reach n from m
    mask out these bits from n.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int diff=n-m;
        int l=0,r=32;
        while(l<r) {
            int mid=(l+r)/2;
            if ((1<<mid)<=diff) l=mid+1;
            else r=mid;
        }
        int mask=l==32?0:~((1<<l)-1);
        return m&n&mask;
    }
};

/***** THird VIsit *****/
/*
    0101
    0110
    0111
    1000
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m==n) return m;
        int k=n-m, t=1;
        int l=0, r=32;
        while (l<r) {
            int mid=(l+r)/2;
            if ((1<<mid)<=k) l=mid+1;
            else r=mid;
        }
        int mask=l==32?0:~((1<<l)-1);
        return m&n&mask;
    }
};

/***** Second Visit *****/
/*
For number 26 to 30, their binary form are:
11010
11011
11100　　
11101　　
11110

Because we are trying to find bitwise AND, so if any bit there are at least one 0 and one 1, it always 0. In this case, it is 11000.
So we are go to cut all these bit that they are different. In this case we cut the right 3 bit.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int i=0;
        while (m!=n) {
            m>>=1;
            n>>=1;
            i++;
        }
        return m<<i;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m==n) return m;
        int diff=n-m;
        int l=0,r=32;
        while (l<r) {
            int mid=(l+r)/2;
            if ((1<<mid)<=diff) l=mid+1;
            else r=mid;
        }
        // cout<<l<<endl;
        int mask=l==32?0:~((1<<l)-1);
        return m&n&mask;
    }
};

/***** First Visit *****/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        /*
            0101 5
            0110 6
            0111 7

            010000111
            010001000
            010001001
            010001010
        */
        if (m==n) return m;
        int diffs=n-m;
        int bits=0;
        while(diffs){ bits++; diffs/=2; }
        return ((m&n)>>bits)<<bits;

    }
};
