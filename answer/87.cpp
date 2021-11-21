/***** Third Visit *****/
/*
    Could be solved by DP
    dp[len][p1][p2] denotes if s1.substr(p1,len) & s2.substr(p2,len) is scramble
    T:O(n^4)
*/
class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        int n=s1.length();
        if (n==1) return s1==s2;
        else if (n==2) {
            string t=s2; reverse(t.begin(),t.end());
            return s1==s2||s1==t;
        }
        vector<int> counter(26,0);
        for (char c:s1) counter[c-'a']++;
        for (char c:s2) counter[c-'a']--;
        for (int c:counter) {
            if (c!=0)
                return false;
        }
        for (int i=1; i<n; ++i) {
            string ls1=s1.substr(0,i), rs1=s1.substr(i);
            string ls2=s2.substr(0,i), rs2=s2.substr(i);
            if (isScramble(ls1,ls2)&&isScramble(rs1,rs2)) return true;
            else {
                ls2=s2.substr(n-i); rs2=s2.substr(0,n-i);
                if (isScramble(ls1,ls2)&&isScramble(rs1,rs2)) return true;
            }
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    1 <= s1.length <= 30
    Limited string length, which means we can adopt recursive to try out all possible scrambling.
    T:O(2^n)/S:O(n)
    -----
    Cause TLE if we dont apply early stop while checking characters of each string.
    T(n) = 2*(T(1)+T(n-1)+...+T(n-1)+T(1))
         = 4*(T(1)+...+T:O(n-1))
         < 4(n-1)T(n-1) = O(4n ^ n)
*/
class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        int n=s1.length();
        if (s1==s2) return true;
        else if (n==1) return false;
        else if (n==2) {
            string k=s2; reverse(k.begin(),k.end());
            return s1==k;
        }
        vector<int> counter(256,0);
        for(char c:s1) counter[c-'a']++;
        for(char c:s2) counter[c-'a']--;
        for(int c:counter) {
            if (c!=0) return false;
        }
        for (int i=1; i<n; ++i) {
            string ls1=s1.substr(0,i), rs1=s1.substr(i);
            string ls2=s2.substr(0,i), rs2=s2.substr(i);
            if (isScramble(ls1,ls2)&&isScramble(rs1,rs2)) return true;
            if (isScramble(s1.substr(0,i),s2.substr(n-i))&&isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
};

/***** First Visit *****/
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
