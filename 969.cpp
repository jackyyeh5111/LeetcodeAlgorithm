/*
    for each unsorted num, find max target then do 2 flip flop.
    ex. 3 2 4 1
        _____
        4 2 3 1
        _______
        1 3 2 4

        do at most 2(n-1) flipflop
        T:O(n^2)/S:O(n)
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A)
    {
        int n=A.size();
        vector<int> ans;
        for (int i=0; i<n-1; ++i) {
            int x=0,target=INT_MIN;
            for (int j=0;j<n-i; ++j) {
                if (A[j]>target) {target=A[j]; x=j;}
            }
            if (x==n-i-1) continue;
            flip(A,x+1, ans);
            flip(A,n-i, ans);

        }
        return ans;
    }

    void flip(vector<int>& A, int i, vector<int> &ans)
    {
        if (i==1) return;
        reverse(A.begin(),next(A.begin(),i));
        ans.push_back(i);
    }
};
/*
3 2 4 1 _
4 2 3 1 2
1 3 2 4 3
3 1 2 4 1
2 1 3 4 2
1 2 3 4 1
*/
