/*
    n = 4, index = 2,  maxSum = 6
    [0,0,1,0]

     n = 4, index = 0,  maxSum = 4
    [2,1,0,0]
     ^

*/
class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {
        maxSum-=n;
        int l=0,r=maxSum+1;
        while (l<r) {
            int mid=l+(r-l)/2;
            if (help(n,index,mid)<=maxSum) l=mid+1;
            else r=mid;
        }
        return l;
    }

    long help(long n, long index, long k) {
        long r=(k+k-(min(n-1,index+k-1)-index))*(min(n-1,index+k-1)-index+1)/2;
        long l=(k+k-(index-max((long)0,index-k+1)))*(index-max((long)0,index-k+1)+1)/2;
        return r+l-k;
    }
};
