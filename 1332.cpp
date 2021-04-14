class Solution {
public:
    int removePalindromeSub(string s)
    {
        if (s=="") return 0;
        string rev=s;
        reverse(s.begin(),s.end());
        if (rev==s) return 1;
        else return unordered_set<char>(s.begin(),s.end()).size();
    }
};
