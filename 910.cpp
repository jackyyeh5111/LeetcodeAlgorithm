/***** Second Visit *****/
/*
    sorting and grouping
    [1,2,3,4,5,6,7], k=3
     + + + - - - -
    T:O(nlogn)/S:O(1)
*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int k)
    {
        sort(A.begin(),A.end());
        int ans=A.back()-A[0], n=A.size();
        for (int i=0; i<n-1; ++i) {
            int low=min(A[0]+k,A[i+1]-k);
            int up=max(A.back()-k,A[i]+k);
            ans=min(ans,up-low);
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    brute force:
    Enumerate 2^n pairs and find min diff.
    T:O(2^n)/S:O(2^n)
    -----
    We are going to find the partition where all nums in left increase K and vice versa.
    T:O(nlogn)/S:O(n)
    1 2 3 || 4 5 6 7 8
    + + +    - - - - -
*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int ans=A.back()-A[0], n=A.size();
        for (int i=0; i<n-1; ++i) {
            int h=max(A.back()-K,A[i]+K);
            int l=min(A[0]+K,A[i+1]-K);
            ans=min(ans,h-l);
        }
        return ans;
    }
};
