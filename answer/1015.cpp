/*
    We use s hashset to check if duplicate remainder we've seen.
    If we've seen it before, then there won't be answer.
    T:O(K)/S:O(K)
    -----
    Use Pigeonhole Principle. With K nuumbers, there must be duplicate remainder in the range of 1~K-1, which means infinite loop. (No answer)
    Else, we will find the answer during first K iteration, i.e. remainder==0.
    T:O(K)/S:O(1)
*/
class Solution {
public:
    int smallestRepunitDivByK(int K)
    {
        if (K%2==0) return -1;
        int remainder=0;
        for (int i=1; i<=K; ++i) {
            remainder=(remainder*10+1)%K;
            if (remainder==0) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int smallestRepunitDivByK(int K)
    {
        int t=1, ans=1;
        unordered_set<int> s;
        while(s.count(t)==0) {
            if (t%K==0) return ans;
            s.insert(t);
            t=(t%K)*10+1;
            ans++;
        }
        return -1;
    }
};
