/***** Second Visit *****/
/*
    string
    1. TRIE
    2. KMP (failure)
    3. treat it as array / [moving window.]
    =====
    brute force:
    check all substrings start from each position.
    T:O(n^2)/S:O(1)
    -----
    ADOBECODEBANC  ABC
    1  2 3   21 3
    Use a moving window with start/end ptr.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<int,int> m;
        for (char c:t) m[c]++;
        int l=0,r=0, ls=s.length(), lt=t.length(), counter=t.length();
        int minl=0, minLength=INT_MAX;
        while (r<ls) {
            if (m[s[r]]>0) counter--;
            m[s[r]]--;
            r++;
            while (counter==0) {
                if(r-l<minLength) {minl=l; minLength=r-l;}
                m[s[l]]++;
                if (m[s[l]]>0) counter++;
                l++;
            }
        }
        return minLength==INT_MAX?"":s.substr(minl, minLength);
    }
};

/***** First Visit *****/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        // Statistic for count of char in t
        for (auto c : t) m[c]++;
        // counter represents the number of chars of t to be found in s.
        size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        size_t size = s.size();

        // Move end to find a valid window.
        while (end < size) {
            // If char in s exists in t, decrease counter
            if (m[s[end]] > 0)
                counter--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            m[s[end]]--;
            end++;
            // When we found a valid window, move start to find smaller window.
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                m[s[start]]++;
                // When char exists in t, increase counter.
                // **If char doesn't exist in t, then its value in map won't be larger than 0
                if (m[s[start]] > 0)
                    counter++;
                start++;
            }
        }

        return minLen==INT_MAX?"":s.substr(minStart, minLen);
    }
};
