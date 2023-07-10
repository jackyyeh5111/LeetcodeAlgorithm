/*
    More elegant approach

    [XXX] X
    XX XX
    XXX X

    dp[i] = dp[i-1] + dp[i-2]

           6 2
    ways:  1 ?
    1. 6 2 ==> 1 ways dp[i-1]
    2. 62  ==> 0 ways dp[i-2]
 */
class Solution2 {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;

    unordered_set<std::string> codes;
    for (int i = 1; i <= 26; i++) codes.insert(to_string(i));

    // transfer function
    int d1 = 1, d2 = 1;
    for (int i = 1; i < s.size(); i++) {
      int num_ways = 0;
      if (codes.find(s.substr(i, 1)) != codes.end()) {
        num_ways += d1;
      }
      if (codes.find(s.substr(i - 1, 2)) != codes.end()) {
        num_ways += d2;
      }

      if (num_ways == 0) return 0;

      d2 = d1;
      d1 = num_ways;
    }
    return d1;
  }
};

/*
          2 1 0 1
    dp: 1 1 2

    (2, 1)
    (21)

    prev        next
    [0]          [0] ==> return 0
    [1 2]        [0] ==> next = prev
    [3 .. 9]     [0] ==> return 0
    [1 2]        [1 .. 9] ==> next = prev + cur
    [2]        [1 .. 6] ==> next = prev + cur
    [2]        [7 .. 9] ==> next = cur
    [0, 3 .. 9]     [1 .. 9] ==> next = cur

          2 2 7

    dp: 1 1 2 3

    (1, 2)
    (12)
    ---
    (1, 2, 1)
    (12, 1)
    (1, 21)
    ---
    (1, 2, 1, 2)
    (12, 1, 2)
    (1, 21, 2)
    (1, 2, 12)
    (12, 12)
 */
class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;

    int prev = 1, cur = 1;
    int next;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '0') {
        if (s[i - 1] != '1' && s[i - 1] != '2') return 0;
        next = prev;
      } else {  // s[i] == 1~9
        if (s[i - 1] == '1')
          next = prev + cur;
        else if (s[i - 1] == '2' && s[i] <= '6')
          next = prev + cur;
        else
          next = cur;
      }
      prev = cur;
      cur = next;
    }
    return cur;
  }
};
