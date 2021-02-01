/***** Second Visit *****/
/*
    brute force:
    merge nums1 and nums2 then return the median one.
    -----
    constraint: The overall run time complexity should be O(log (m+n))
    [1,2,3] 3
    [3,4,5,6,7,8] 6...9/2-3

    [1,2,3] 3
    [3,4,5,6,7,8,9] 7...9/2-3   -> (N-1)/2

    [21,22,23] 3
    [3,4,5,6,7,8] 6...9/2
    binary search on HOW MANY NUMS IN NUMS1 SHOULD WE USE
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size()>nums2.size()) swap(nums1,nums2);
        int n1=nums1.size(),n2=nums2.size();
        int l=0, r=n1;
        while (l<=r) {
            int p1=(l+r)/2;
            int p2=(n1+n2+1)/2-p1; // Notice that it may get under/overflow if n1>n2
            int maxLeft1=p1==0?INT_MIN:nums1[p1-1];
            int minRight1=p1==n1?INT_MAX:nums1[p1];
            int maxLeft2=p2==0?INT_MIN:nums2[p2-1];
            int minRight2=p2==n2?INT_MAX:nums2[p2];

            if (maxLeft1<=minRight2&&maxLeft2<=minRight1) {
                if ((n1+n2)%2) return max(maxLeft1,maxLeft2);
                else return (max(maxLeft1,maxLeft2)+min(minRight1,minRight2))/2.0;
            }
            else if (maxLeft1>minRight2) r=p1-1;
            else l=p1+1;
        }
        return -1;
    }
};

/***** First Visit *****/
/*
    merge 2 sorted array then return median
    T:O(m+n)/S:O(1)
    -----
    binary search on first vector to split num1/num2
    Note the criteria of mid term.
    T:O(logn)/S:O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size()>nums2.size()) swap(nums1,nums2);
        int x=nums1.size(), y=nums2.size();
        int l=0,r=x;
        while(l<=x) {
            int px=(l+r)/2;
            int py=(x+y+1)/2-px;

            int maxLeftX=px==0?INT_MIN:nums1[px-1];
            int minRightX=px==x?INT_MAX:nums1[px];

            int maxLeftY=py==0?INT_MIN:nums2[py-1];
            int minRightY=py==y?INT_MAX:nums2[py];

            if (maxLeftX<=minRightY&&
                maxLeftY<=minRightX) {
                if((x+y)%2) return max(maxLeftX,maxLeftY);
                else return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
            }
            else if (maxLeftX>minRightY)
                r=px-1;
            else l=px+1;
        }
        return -1;
    }
};
