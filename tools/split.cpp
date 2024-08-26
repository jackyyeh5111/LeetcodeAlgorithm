#include "../utils.hpp"

#include <iostream>

using namespace std;

// vector<string> split(const string& str, char delimiter) {
//     vector<string> tokens;
//     int start = 0;
//     for (int end = 0; end < str.size(); end++) {
//         if (str[end] != delimiter) continue;
//         string token = str.substr(start, end - start);
//         tokens.push_back(token);
//         start = end + 1;
//     }

//     // handle last token
//     tokens.push_back(str.substr(start));
//     return tokens;
// }
vector<string> split(const string& str, char delimiter) {
    /* 
        12,,2,3,4
     */
    vector<string> tokens;
    int end = 0;
    while (end < str.size()) {
        int start = end;
        // keep going until encounter '\n' or char does not equal delimiter
        while(end < str.size() && str[end] != delimiter)
            end++;
        // skip continuous delimiter
        if (end - start > 0)
            tokens.push_back(str.substr(start, end - start));
        end++;
    }
    return tokens;
}

#include <sstream>
int main() {
    cout << "# input:";
    string num_input;
    getline(cin, num_input);

    cout << "arr: ";
    string arr;
    getline(cin, arr);

    vector<string> split_arr = split(arr, ',');

    // display
    for (int i = 0; i < split_arr.size(); i++) {
        cout << split_arr[i];
        if (i != split_arr.size() - 1)
            cout << ' ';
    }
    cout << endl;

    
    // string input = "abc,,def,ghi";             // to implement the function like split(",") in Java
    // stringstream ss(input);                   // equal to ss << input
    // string token;

    // while(getline(ss, token, ',')) {
    //     cout << token << '\n';
    // }


    return 0;
}
