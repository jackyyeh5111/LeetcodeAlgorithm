#include "../utils.hpp"

#include <iostream>

using namespace std;

vector<string> split(const string &str, char delimiter) {
    int start = 0;
    vector<string> tokens;
    for (int end = 0; end < str.size(); end++) {
        if (str[end] != delimiter) continue;
        string token = str.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
    }

    // handle the last token
    string token = str.substr(start);
    tokens.push_back(token);
    return tokens;
}

int main() {
    cout << "# input value: ";
    string num_input;
    getline(cin, num_input);

    cout << "array to split: ";
    string arr;
    getline(cin, arr);
    vector<string> split_arr = split(arr, ',');

    // print out
    for (int i = 0; i < split_arr.size(); i++) {
        cout << split_arr[i];
        if (i != split_arr.size() - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}