// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/***** Second Visitt *****/
/*
    [o,o,o]
    [x,x,x]
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int firstBadVersion(int n)
    {
        int l=0, r=n;
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (!isBadVersion(mid)) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};

/***** First Visitt *****/
/*
    binary Search
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int firstBadVersion(int n)
    {
        long l=0, r=(long)n+1;
        while (l<r) {
            int mid=(l+r)/2;
            if (isBadVersion(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
