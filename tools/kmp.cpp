#include "../utils.hpp"

/*
    ref:
        https://www.youtube.com/watch?v=af1oqpnH1vA

    main string:
    A B A B A B C A A

    A B A B C A B A
        A B A B C A B A

    sub string:
          A B A B C A B A D
    next: 0 0 1 2 0 1 2 3

    definition of next: 跳過多少字元的比較(之前已經比對過)
    how to buildNext:
        1. value of next cannot euqal to the string length
        2.
 */
void buildNext(string str, vector<int> &next) {
  int N = str.size();
  next.resize(N);

  int ptr = 0;
  for (int i = 1; i < N; i++) {
    if (str[i] == str[ptr]) {
      ptr++;
      next[i] = ptr;
    } else {
      while (ptr != 0) {
        ptr = next[ptr - 1];
        if (str[i] == str[ptr]) {
          ptr++;
          next[i] = ptr;
          break;
        }
      }
    }
  }
}

/*
    A B A B A B C A A

    sub_str: A B A B C
       next: 0 0 1 2 0
 */
int kmp(string main_s, string sub_s) {
  vector<int> next;
  buildNext(sub_s, next);

  // print(next);

  int i = 0, j = 0;
  while (i < main_s.size()) {
    if (main_s[i] == sub_s[j]) {
      i++;
      j++;
    } else if (j > 0) {
      j = next[j - 1];
    } else {  // does not match at the first char in sub_str
      i++;
    }

    if (j == sub_s.size()) {
      return i - j;
    }
  }
  return -1;
}

int main() {
  string s = "bbac";
  string sub_s = "aba";
  std::cout << kmp(s, sub_s) << '\n';
  return 0;
}