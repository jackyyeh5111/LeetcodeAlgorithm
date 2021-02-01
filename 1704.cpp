class Solution {
public:
    bool halvesAreAlike(string s)
    {
        unordered_set<char> vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int counter=0;
        for (char c:s) {
            if (vowels.count(c)!=0) counter++;
        }
        if (counter%2) return false;
        int t=0;
        for (int i=0; i<s.length()/2; ++i)
            t+=(vowels.count(s[i])!=0);
        return t==counter/2;
    }
};
