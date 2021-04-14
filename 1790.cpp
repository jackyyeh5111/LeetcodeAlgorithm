/*
    abcdefgh
    fghcdeab

    abcd
      ^

    "siyolsdcjthwsiplcc j buceoxm p jgrauocx"
    "siyolsdcjthwsiplcc p buceoxm j jgrauocx"
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1==s2) return true;
        int n=s1.length();
        int l=0,r=n-1;
        while (s1[l]==s2[l]) l++;
        while (s1[r]==s2[r]) r--;
        s1=s1.substr(l,r-l+1);
        s2=s2.substr(l,r-l+1);
        n=r-l+1;
        for (int len=1; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j=i+len-1;
                string comb=s1.substr(j+1)+s1.substr(i,len)+s1.substr(0,i);
                if (comb==s2)
                    return true;
            }
        }
        return false;
    }
};
