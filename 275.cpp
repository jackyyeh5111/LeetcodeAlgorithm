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
        Then we can further sse binary search.
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
