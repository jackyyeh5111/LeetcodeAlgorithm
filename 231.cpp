/********************** Second Visit **********************/
/*
    determine wheter only 1 digit in binary.
    -----
    n&n-1
    T:O(1)/S:O(1)
    -----
    iterative
    T:O(logn)
    -----
    binary search
    T:O(log32)
*/
class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n<=0) return false;
        return !(n&(n-1));
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        int l=0, r=31;
        while(l<=r) {
            int mid=(l+r)/2;
            if (1<<mid == n) return true;
            else if (1<<mid >n) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
/********************** First Visit **********************/
class Solution {
public:
    // T:O(1)
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        return !(n&(n-1));
    }
};

class Solution {
public:
    // T:O(log32)
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        int low=0; int high=31;
        while(low<high) {
            int mid = (low+high)/2;
            cout<<low<<","<<high<<endl;
            if (1<<mid == n) return true;
            if (1<<mid > n) high=mid-1;
            if (1<<mid < n) low=mid+1;
        }
        return 1<<low==n;
    }
};
