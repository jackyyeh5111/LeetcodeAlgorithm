
/********* Knuth-Morris-Pratt ************/

class Solution {
public:
    // T:O(m+n), S:O(m)
    // Notice j, 33% for j-- and 90% for j=ans[j-1]
    int strStr(string haystack, string needle)
    {
        if (needle=="") return 0;
        else if (haystack=="") return -1;

        vector<int> failure = getFailure(needle);
        int haystack_size = haystack.length();
        int needle_size = needle.length();
        int i=0, j=0;
        while(j-i <= haystack_size-needle_size) {
            if (i>0 && haystack[j]!=needle[i])
                i = failure[i-1];
            else if (haystack[j]==needle[i]) {
                i++; j++;
            }
            else
                j++;

            if (i>needle.size()-1)
                return j-i;
        }
        return -1;
    }

    vector<int> getFailure(string pattern)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i=1; i<pattern.size(); ++i) {
            int j=ans[ans.size()-1];
            while (j>0&&pattern[j]!=pattern[i]) j=ans[j-1]; // j--
            if (pattern[i] == pattern[j])
                ans.push_back(j+1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
