class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // T:O(m+n)
        int p1=0; int p2=0; int total=m+n;
        while(p2<n) {
            cout<<p1<<","<<p2<<endl;
            if (p1<m&&nums1[p1]<=nums2[p2]) p1++;
            else {
                for (int k=total-2; k>=p1; --k) nums1[k+1]=nums1[k];
                nums1[p1]=nums2[p2];
                p2++; p1++; m++;
            }
        }
    }
};
