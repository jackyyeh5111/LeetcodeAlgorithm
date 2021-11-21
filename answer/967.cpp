/*
    backtracking
    say 3, 2
    1 1+2 1+2+2
    1 1+2 1+2-2
    2 2+2 2+2+2
    ...
    5 5+2 5+2+2
    5 5+2 5+2-2
    7 7+2 7+2+2 (x)
    7 7+2 7+2-2 (x)
    ---------
    T:O(n*2^n)/S:O(n) which is the depth of recursive
*/
class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int N, int K)
    {
        if (N==1) ans.push_back(0);
        for (int i=1; i<10; ++i) {
            help(N,K,1,i);
        }
        return ans;
    }

    void help(int N, int K, int l, int val)
    {
        if (l==N) {ans.push_back(val); return;}
        if (K==0) help(N,K,l+1,val*10+val%10);
        else {
            if (val%10+K<=9) help(N,K,l+1,val*10+val%10+K);
            if (val%10-K>=0) help(N,K,l+1,val*10+val%10-K);
        }
    }
};
