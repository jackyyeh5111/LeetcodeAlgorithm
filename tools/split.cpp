#include "../utils.hpp"

#include <iostream>
#include <sstream>
using namespace std;

vector<string> split(const string &str, char delimiter) {
    /* 
        1,23,,,3,,4,
     */
    vector<string> tokens;
    int end = 0;
    while(end < str.size()) {
        int start = end;
        while(end < str.size() && str[end] != delimiter)
            end++;
        if (start < end)
            tokens.push_back(str.substr(start, end - start));
        end++;
    }
    return tokens;
}

int main() {
    cout << "# of input: ";
    string num_input;
    getline(cin, num_input);

    cout << "input arr: ";
    string arr;
    getline(cin, arr);
    vector<string> split_arr = split(arr, ',');

    // display
    stringstream output;
    for (int idx = 0; idx < split_arr.size(); idx++) {
        output << split_arr[idx] << ' ';
    }
    string str = output.str();
    str.pop_back();
    cout << str << endl;

    return 0;
}