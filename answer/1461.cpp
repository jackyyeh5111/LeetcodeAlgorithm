class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<int> myset;
        int mask=0,cur=0,n=s.length();
        if (n<=k) return false;
        for (int i=0; i<k; ++i)
            mask=(mask<<1)|1;
        for (int i=0; i<n; ++i) {
            cur=(cur<<1)|(s[i]=='1');
            if (i>=k-1) {
                cur=cur&mask;
                myset.insert(cur);
            }
        }

        return myset.size()==(1<<k);
    }
};
