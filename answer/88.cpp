/***** Fifth Visit *****/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p=nums1.size()-1;
        m--; n--;
        for (int i=p; i>=0; i--) {
            if (m>=0&&n>=0&&nums1[m]>=nums2[n]) nums1[i]=nums1[m--];
            else if (n>=0) nums1[i]=nums2[n--];
            else break;
        }
    }
};

/***** Fourth Visit *****/
/*
    Top down linear probing
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int idx1=m-1,idx2=n-1;
        for (int i=m+n-1; i>=0; --i) {
            if (idx1>=0&&idx2>=0&&nums1[idx1]<=nums2[idx2])
                nums1[i]=nums2[idx2--];
            else if (idx1>=0&&idx2>=0&&nums1[idx1]>nums2[idx2])
                nums1[i]=nums1[idx1--];
            else if (idx1<0)
                nums1[i]=nums2[idx2--];
            else
                nums1[i]=nums1[idx1--];
        }
    }
};

/***** Third Visit *****/
/*
    [1,2,3,0,0,0]
       ^
    [2,5,6]
     ^
    [1,2,2,3,5,6]
       ^
    Top-down 2 ptr
    T:O(m+n)/S:O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1;
        while (n>0&&m>0) {
            if (nums1[m-1]>nums2[n-1])
                nums1[k--]=nums1[--m];
            else nums1[k--]=nums2[--n];
        }
        while (n>0) nums1[k--]=nums2[--n];
    }
};

/***** Second Visit *****/
/*
    Insertion sort
    T:O(n^2)/S:O(1)
    -----
    a container to store result
    T:O(n)/S:O(n)
    -----
    find m smallest nums and swap into nums1, then fill the rest according to nums2.
    T:1 pass O(n)/S:O(1)
    WRONG!!!
    -----
    Top-down sorting with 1 pass
    4,5,6,0,5,6
    ^     ^
    1,2,3
        ^
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=m-1,j=n-1,t=m+n-1;
        while (i>=0&&j>=0) {
            if (nums1[i]>=nums2[j]) nums1[t--]=nums1[i--];
            else nums1[t--]=nums2[j--];
        }
        while (j>=0) nums1[t--]=nums2[j--];
    }
};

/***** First Visit *****/
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
