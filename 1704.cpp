/***** Second Visit *****/
class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int n=s.length();
        unordered_set<char> vowels={'a','e','i','o','u'};
        int left=0,right=0;
        for (int i=0; i<n; ++i) {
            if (vowels.count(tolower(s[i]))==0) continue;
            if (i<n/2) left++;
            else right++;
        }
        return left==right;
    }
};

/*
    T:O(n)/S:O(1)
    assert(halvesAreAlike("kb")==true)
    assert(halvesAreAlike("ie")==true)
    assert(halvesAreAlike("ab")==false)
    assert(halvesAreAlike("ba")==false)
*/

/***** First Visit *****/
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
