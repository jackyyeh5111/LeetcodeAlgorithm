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
