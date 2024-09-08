class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        unordered_map<int, int> char_to_cnt;
        for (int right = 0; right < s.size(); right++) {
            char_to_cnt[s[right]]++;
            while(char_to_cnt[s[right]] == 2) {
                char_to_cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

/* 
    hashmap:
        a: 1
        b: 0
        c: 1

    abcab
     l
       r
 */