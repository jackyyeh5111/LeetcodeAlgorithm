#include "../utils.hpp"

#include <iostream>

using namespace std;
// vector<string> split(string s, char delimiter) {
//     vector<string> tokens;
//     int start = 0;
//     for (int i = 0; i < s.size(); i++) {
//         char ch = s[i];
//         if (ch == delimiter) {
//             tokens.push_back(s.substr(start, i - start));
//             start = i + 1;
//         }
//     }
//     tokens.push_back(s.substr(start, s.size() - start));
//     return tokens;
// }

vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    int start = 0;;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            tokens.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

int main() {
    cout << "Your input: ";
    
    string input;
    getline(cin, input);
    int num_input = stoi(input);

    getline(cin, input);
    vector<string> tokens = split(input, ' ');
    print(tokens);
    return 0;
}