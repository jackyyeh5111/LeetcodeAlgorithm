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
