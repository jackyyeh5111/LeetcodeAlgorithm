/*
    if the length of string is less than 3, the beauty is 0.
    brute force:
        enumerate all substrings: T:O(n^2)
        find the beauty: T:O(n) -> T:O(log(26))
*/
class Solution {
public:
    int beautySum(string s)
    {
        int n=s.length(), ans=0;
        for (int i=0; i+2<n; ++i) {
            unordered_map<char,int> table;
            multiset<int> mst;
            table[s[i]]++; table[s[i+1]]++;
            mst.insert(table[s[i]]);
            if (s[i]!=s[i+1]) mst.insert(table[s[i+1]]);
            for (int j=i+2; j<n; ++j) {
                if (table[s[j]]>0) mst.erase(mst.find(table[s[j]]));
                mst.insert(++table[s[j]]);
                ans+=(*mst.rbegin()-*mst.begin());

            }
        }
        return ans;
    }
};
