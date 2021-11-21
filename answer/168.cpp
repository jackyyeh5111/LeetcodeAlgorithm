/********** Second Visit **********/
class Solution {
public:
    string convertToTitle(int n)
    {
        string ans="";
        n--;
        while (n>=0) {
            ans.insert(ans.begin(),'A'+n%26);
            n=n/26-1;
        }
        return ans;
    }
};

/********** First Visit **********/
class Solution {
public:
    string convertToTitle(int n)
    {
        /*
            0  A
            1  B
            ...
            25 Z
            26 AA
            27 AB
            ...
            701 ZZ
            702 AAA
        */
        string ans="";
        n--;
        while(n>=0) {
            int remain=n%26; //25 1
            n=n/26-1;
            ans.insert(ans.begin(),'A'+remain);
        }
        return ans;
    }
};
