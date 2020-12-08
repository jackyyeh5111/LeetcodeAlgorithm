/***** Second Visit *****/
/*
    Bottom-up
    T:O(k)/S:O(1)
    -----
    "hello world"
    "hello world  "
*/
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int n=s.length(), i=n-1;
        int ans=0;
        while(i>=0&&s[i]==' ') --i;
        while(i>=0&&s[i]!=' ') {ans++; --i;}
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        if (s.length()==0) return 0;
        // bottom up O(n)
        int i=s.length();
        for (; i>0; --i) {
            if (s[i-1]!=' ') break;
        }
        s=s.substr(0,i);
        i=s.length()-1;
        for (; i>=0; --i) {
            if (s[i]==' ') break;
        }

        return s.length()-i-1;
    }
};
