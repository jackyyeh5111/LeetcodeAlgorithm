#include "utils.hpp"

#include <iostream>

using namespace std;
vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == delimiter) {
            tokens.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }
    tokens.push_back(s.substr(start, s.size() - start));
    return tokens;
}
int main() {
    string s = "app ban cat";
    vector<string> tokens = split(s, ' ');
    print(tokens);
    return 0;
}