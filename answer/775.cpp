/*
    brute force: T:O(n^2)
    -----
    if we utilize multiset, it takes O(n) for disatnce, thus T:O(n^2) again.
    local: T:O(n)
    global: T:O(nlogn)
    T:O(nlogn)/S:O(n)
    -----
    [0,1,2,3,4,5]
    [1,0,2,3,4,5]
    [2,1,0,3,4,5]
    [3,1,2,0,4,5]
    -----
    All local inversions are global inversions.
    If the number of global inversions is equal to the number of local inversions,
    it means that all global inversions in permutations are local inversions.
    It also means that we can not find A[i] > A[j] with i+2<=j.

    To place number i, we could only place i at A[i-1], A[i] or A[i+1].
    refers: https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i=0; i<A.size(); ++i) {
            if (abs(A[i]-i)>1) return false;
        }
        return true;
    }
};
