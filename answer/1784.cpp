class Solution {
public:
    bool checkOnesSegment(string s)
    {
        int i=0,n=s.length();
        while (s[i]=='1') i++;
        while (i<n) {
            if (s[i]!='0') return false;
            i++;
        }
        return true;
    }
};
