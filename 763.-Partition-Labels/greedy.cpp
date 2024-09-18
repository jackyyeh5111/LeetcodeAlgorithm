class Solution {
public:
    vector<int> partitionLabels(string s) {
        // create hashmap
        unordered_map<char, int> char_to_end; 
        for (int idx = 0; idx < s.size(); idx++) {
            char_to_end[s[idx]] = max(char_to_end[s[idx]], idx);
        }

        // greedy algo
        int start = 0;
        int end = 0;
        vector<int> output;
        for (int idx = 0; idx < s.size(); idx++) {
            if (idx > end) {
                output.push_back(end - start + 1);
                start = idx;
            }
            end = max(end, char_to_end[s[idx]]);
        }
        output.push_back(end - start + 1);
        return output;
    }
};

/* 
    [aba][c]
            ^
    start = 3
    end = 3
    output: [3, 1]
    
    hashmap = { // char -> end
        a: 2
        b: 1
        c: 3
    }

    1) create hashmap to store end index of characters
    2) iterate string once, greedy partition
 */