/*
    hashmap to do char counting
    grab all pairs and check odd value exist or not.
    Actually we can use a char array to replace hashmap.
*/
class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char,int> m;
        for (char c:s) m[c]++;
        bool isOdd=false; int ans=0;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            ans+=it->second/2;
            isOdd=isOdd||it->second%2;
        }
        return ans*2+isOdd;
    }
};
