/*
    s length max 100000
    "aacaba"
          ^
    // unordered_set<char> left,right
    vector<int> leftCnt(26,0)
    vector<int> rightCnt(26,0)

    1 a
    3a 1b 1c
    condition: pq cannot be empty

    T:O(n)/S:O(1) 2 pass

*/
class Solution {
public:
    int numSplits(string s)
    {
        int n=s.length(), ans=0;
        vector<int> leftCnt(26,0);
        vector<int> rightCnt(26,0);

        // 1 pass
        for (int i=0; i<n; ++i) {
            rightCnt[s[i]-'a']++;
        }

        // 2 pass
        for (int i=1; i<n; ++i) {
            rightCnt[s[i-1]-'a']--;
            leftCnt[s[i-1]-'a']++;
            int a=0,b=0;
            for (int j=0; j<26; ++j) {a+=leftCnt[j]>0; b+=rightCnt[j]>0;}
            if (a==b) ans++;
        }
        return ans;
    }
};
