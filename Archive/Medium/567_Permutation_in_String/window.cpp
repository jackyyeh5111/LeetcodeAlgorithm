/*
Given two strings s1 and s2, write a function to return true if s2 contains the
permutation of s1. In other words, one of the first string's permutations is
the substring of the second string.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> m1(26, 0), m2(26, 0);
        for (char& c : s1)
            m1[c-'a']++;
        for (int i=0; i<s2.length(); ++i) {
            m2[s2[i]-'a']++;
            if (i >= s1.length()) m2[s2[i-s1.length()]-'a']--;
            if (m1 == m2) return true;
        }
        return false;
    }
};
