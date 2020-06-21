class Solution {
public:
    /*
    T(n)= 2*((T(1)+T(n-1))+(T(2)+T(n-2))+...+(T(n-1)+T(1)))
        = 4*(T(1)+...+T(n-1))
        <= 5*T(n-1)
        = O(5^n)
    */
    bool isScramble(string s1, string s2)
    {
        if (s1==s2) return true;
        int len1=s1.length(), len2=s2.length();
        if (len1!=len2) return false;
        vector<int> counter(256,0);
        for (char c:s1) counter[c]++;
        for (char c:s2) counter[c]--;
        for (auto c: counter) {
            if (c != 0) {return false;}
        }
        for (int i=1; i<len1; ++i) {
            if (isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i),s2.substr(len1-i))&&isScramble(s1.substr(i),s2.substr(0,len1-i)))
                return true;
        }
        return false;
    }
};
