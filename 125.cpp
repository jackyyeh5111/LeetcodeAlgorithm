/**************** Second Visit ****************/
/*
    Notice indexing out of boundary!!!
    Check palindrome, we only need to compare half of string.
    Thus our criteria could set in the middle rather than 0/size,
*/
class Solution {
public:
    bool isPalindrome(string s)
    {
        int n=s.length(); int i=0, j=n-1;
        while (i<n&&j>=0&&i<j) {
            while(i<n&&!isalnum(s[i])) ++i;
            while(j>=0&&!isalnum(s[j])) --j;
            if (i>=n||j<0) break;
            if (tolower(s[i])!=tolower(s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};

/**************** First Visit ****************/
class Solution {
public:
    bool isPalindrome(string s)
    {
        /*
            typical valid palindrome of string could be solved by stack the first half
            part of string then start comparison. But here we cannot find the exact
            index of middle, thus we could apply 2 ptr strategy. start from left/right
            endian and conduct a comparison, (skip cases/non alphanumeric meanwhile).
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
