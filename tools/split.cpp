#include "../utils.hpp"

#include <iostream>
#include <sstream>
using namespace std;

vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    int end = 0;
    /* 
        1,22,3,,4,
               ^
               s
     */
    while(end < str.size()) {
        int start = end;
        while(end < str.size() && str[end] != delimiter)
            end++;
        if (end - start > 0)
            tokens.push_back(str.substr(start, end - start));
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
    return 0;
}

// int main() {
//     cout << "# of input: ";
//     string num_input;
//     getline(cin, num_input);

//     cout << "input arr: ";
//     string arr;
//     getline(cin, arr);
//     vector<string> split_arr = split(arr, ',');

//     // display
//     stringstream output;
//     for (int idx = 0; idx < split_arr.size(); idx++) {
//         output << split_arr[idx] << ' ';
//     }
//     string str = output.str();
//     str.pop_back();
//     cout << str << endl;

//     return 0;
// }