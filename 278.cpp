// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

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
