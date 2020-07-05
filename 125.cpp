class Solution {
public:
    bool isPalindrome(string s)
    {
        /*
            typical valid palindrome of string could be solved by stack the first half
            part of string then start comparison. But here we cannot find the exact
            index of middle, thus we could apply 2 ptr strategy. start from left/right
            endian and conduct a comparison, (skip cases/non alphanumeric neamwhile).
            T:O(n), S:O(1)
        */
        int l=0, r=s.length()-1;
        while(l<r) {
            while (l<r&&!isalnum(s[l])) l++;
            while (l<r&&!isalnum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++; r--;
        }
        return true;

    }
};
