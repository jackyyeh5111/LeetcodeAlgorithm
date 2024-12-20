#include "../utils.hpp"

#include <iostream>
#include <sstream>
using namespace std;

vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    int end = 0;
    while(end < str.size()) {
        int start = end;
        while(end < str.size() && str[end] != delimiter)
            end++;
        if (start < end)
            tokens.emplace_back(str.substr(start, end - start));
        end++;
    }
    return tokens;
}

int main() {
    cout << "input arr: ";
    string arr;
    getline(cin, arr);
    vector<string> tokens = split(arr, ',');
    
    stringstream ss;
    for (int i = 0 ;i < tokens.size(); i++) {
        ss << tokens[i] << ' ';
    }
    string str = ss.str();
    str.pop_back();
    cout << str;
    cout << '\n';
    return 0;
}