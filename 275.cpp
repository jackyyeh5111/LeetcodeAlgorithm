/******* Second Visit *******/
/*
    Sorted order
    0 1 3 5 6
    5 4 3 2 1
    iterative find val>index+1
    T:O(n)/S:O(1)
    --------------
    binary search to find val>index+1
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n=citations.size();
        int l=0, r=n;
        // l is the minima index that satisfies condition
        while (l<r) {
            int mid=(l+r)/2;
            if (citations[mid]>=n-mid) r=mid;
            else l=mid+1;
        }
        return n-l;
    }
};

/******* First Visit *******/
class Solution {
public:
    // T:O(logn)
    int hIndex(vector<int>& citations)
    {
        /*
        First, I'd like to check if Im fully understand this question.
        []:0
        [7]:1
        [1,2]:1, 1 larger than 1 and 1 not larger than 1,
        (thought) Since it's sorted:
        we can do brute force with O(n), for i=0~length, check if valid, return.
        Then we can further use binary search.
        */
        int l=0, r=citations.size()-1; int n=citations.size();
        while(l<=r) {
            int mid=(l+r)/2;
            // cout<<l<<","<<r<<endl;
            if (citations[mid]<n-mid) l=mid+1;
            else if (mid>0&&citations[mid-1]>n-mid) r=mid-1;
            else return n-mid;
        }
        // cout<<l<<","<<r<<endl;
        return n-l;
    }
};
