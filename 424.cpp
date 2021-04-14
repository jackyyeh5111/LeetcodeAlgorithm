/*
    brute force:
    treat each char as the beginning char and go right to check if k changes needed.
    Note that after forward checking, we should take care of residual k backward as well.

    Find the max length.
    T:O(n^2)/S:O(n)
    -----
    sliding window solution
    Considering the sliding window, maintain the max frequent char inside.
    The changes we need is window size - max frequency, say t.

    If the t is less than k, it means we should shrink the window size as we dont have enough changes to form repeating string of current size. Note we should reduce the frequency of left char while shrinking.

    otherwise, increase the window size.
    T:O(n)/S:O(26)
*/

// T:O(n)/S:O(26)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n=s.length(),ans=0,wsize=0,maxFreq=0;
        unordered_map<char,int> mp;
        for (int i=0; i<n; ++i) {
            maxFreq=max(maxFreq, ++mp[s[i]]);
            if (wsize-maxFreq<k) wsize++;
            else mp[s[i-wsize]]--;
        }
        return wsize;
    }
};

// T:O(n^2)/S:O(1)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n=s.length(),ans=0;
        char prev=0;
        for (int i=0; i<n; ++i) {
            if (prev==s[i]) continue;
            prev=s[i];
            int j=i+1,t=k;
            char c=s[i];
            while (j<n&&t>0) {
                if (s[j]!=c) t--;
                j++;
            }
            while (j<n&&s[j]==c) j++;
            ans=max(ans,j-i+min(t,i));
        }
        return ans;
    }
};
