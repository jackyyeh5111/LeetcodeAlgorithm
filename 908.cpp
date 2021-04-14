/***** Second Visit *****/
/*
    1 2 3 4 5 6
*/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K)
    {
        auto t=minmax_element(A.begin(),A.end());
        if (*t.second-K<=*t.first+K) return 0;
        else return *t.second-*t.first-2*K;
    }
};

/***** First Visit *****/
/*
    Find the min/max num and see if they are overlap.
    If so, then theie diff could be 0, else max-min.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int cmin=A[0],cmax=A[0];
        for (int a:A) {
            cmin=min(cmin,a);
            cmax=max(cmax,a);
        }
        int ans=max(0,cmax-cmin-2*K);

        return ans;
    }
};
