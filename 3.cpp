#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
    ref:
    904.cpp
 */
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> umap;
        int cnt = 0;
        int l = 0;
        int r = 0;
        int n  = s.size();
        int ans = 0;
        while (r < n) {
            if (umap[s[r]] == 1) cnt ++;
            umap[s[r]]++;
            r++;
            while(l < r && cnt > 0) {
                umap[s[l]]--;
                if (umap[s[l]] == 1) cnt --;
                l++;
            }
            
            ans = max(ans, r-l);
        }
        
        return ans;
        
    }
};