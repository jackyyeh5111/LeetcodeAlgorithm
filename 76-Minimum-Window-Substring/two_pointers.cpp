/* 
   num_unique_char = 0
   hashmap:
    A:-1
    B:0
   
    ACBDAB
    l
      r

    output = "AB"

      s = ACBD
      t = AB
    ans = ACB
 */

class Solution {
public:
    string minWindow(string s, string t) {
        // create hashmap for t
        unordered_map<char, int> char_to_cnt;
        for (char ch : t) char_to_cnt[ch]++;

        // two pointers loop through s
        int num_unique_char = char_to_cnt.size();
        int ans_start = 0, min_len = INT_MAX;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // process right pointer
            if (char_to_cnt.count(s[right])) {
                char_to_cnt[s[right]]--;
                if (char_to_cnt[s[right]] == 0)
                    num_unique_char--;
            }

            while(num_unique_char == 0) {
                int len = right - left + 1;
                if (len < min_len) {
                    ans_start = left;
                    min_len = len;
                }

                // process left pointer
                if (char_to_cnt.count(s[left])) {
                    char_to_cnt[s[left]]++;
                    if (char_to_cnt[s[left]] == 1)
                        num_unique_char++;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(ans_start, min_len);
    }
};

/*
    Time Limit Exceeded!

    Two pointers

    s = "ACBBA"  t = "AB"
    int total_diff_char = 2
    num_diff_char = 2
    t_cnt = {
        A: 0
        B: 0
    }

    CACBBA
     l
       r
 */
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<int, int> t_cnt;
    for (char ch : t) ++t_cnt[ch];

    int left = 0, right = 0;
    int num_diff_char = 0;
    string ans = "";
    while (right < s.size()) {
      if (t_cnt.find(s[right]) != t_cnt.end()) {  // important
        --t_cnt[s[right]];
        if (t_cnt[s[right]] == 0) ++num_diff_char;
      }

      ++right;

      /*
          CACBBA
            l
              r
       */
      while (left < right && num_diff_char == t_cnt.size()) {
        if (ans == "" || right - left < ans.size())
          ans = s.substr(left, right - left);

        if (t_cnt.find(s[left]) != t_cnt.end()) {  // important
          ++t_cnt[s[left]];
          if (t_cnt[s[left]] > 0) --num_diff_char;
        }
        ++left;
      }
    }
    return ans;
  }
};

/* Wrong answer */
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> chars;
    for (char ch : t) chars[ch]++;

    // slide through string s
    int left = 0, right = 0;
    string ans = "";
    int num_diff_char = 0;

    for (; right < s.size(); right++) {
      char ch = s[right];
      if (chars.find(ch) != chars.end()) {
        chars[ch]--;
        if (chars[ch] == 0) num_diff_char++;  // 1
      }

      right++;  // Wrong here! Variable right plus one at each loop. No need to
                // add here.
      while (num_diff_char == chars.size() && left < right) {
        // update ans substr
        int substr_len = right - left;
        if (num_diff_char == chars.size()) {
          if (ans.size() == 0 || substr_len < ans.size())
            ans = s.substr(left, substr_len);
        }

        // update the left pointer
        char ch = s[left];
        if (chars.find(ch) != chars.end()) {
          chars[ch]++;
          if (chars[ch] > 0) num_diff_char--;
        }
        left++;
      }
    }
    return ans;
  }
};

/* Wrong answer! */
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";
    unordered_map<char, int> count_t;
    for (char ch : t) count_t[ch]++;

    unordered_map<char, int> count_s;
    int left = 0, right = 0;
    int num_matched = 0;
    string ans = "";
    while (right < s.size()) {
      char ch = s[right];
      count_s[ch]++;
      if (count_s[ch] == count_t[ch])  // wrong here!
        num_matched++;
      right++;

      // move left ptr
      while (num_matched == count_t.size() && left < right) {
        // check if ans should be modified?
        int strlen = right - left;  // 4
        if (ans == "" || strlen < ans.size()) ans = s.substr(left, strlen);

        char ch = s[left];
        count_s[ch]--;
        if (count_s[ch] < count_t[ch]) num_matched--;
        left++;
      }
    }
    return ans;
  }
};

