/*
    brute force:
    found all nums and enumerate all possible nums
    T:O(2^32)/S:O(32)
    -----
    Same as next lexical order perm problem
    34521 -> 35421 -> 35124
     ^^
    35124
    T:O(logn)/S:O(logn)
*/
class Solution {
public:
    int nextGreaterElement(int n)
    {
        string sn=to_string(n);
        int i=sn.length()-2;
        for (; i>=0; --i) {
            if (sn[i]<sn[i+1]) break;
        }
        if (i<0) return -1;
        int j=sn.length()-1;
        for (; j>i; --j){
            if (sn[j]>sn[i]) break;
        }
        swap(sn[i],sn[j]);
        reverse(sn.begin()+i+1,sn.end());
        long next=stol(sn);
        return next>INT_MAX?-1:next;
    }
};
