class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> encoded_set;
        for (const string& str : dict) {
            for (int idx = 0; idx < str.size(); idx++) {
                string encoded = str;
                encoded[idx] = '*';
                if (encoded_set.count(encoded)) return true;
                encoded_set.insert(encoded);
            }
        }
        return false;
    }
};

/* 
    Approach 1:
        sort and check => O(nlogn * m)
 
    Approach 2:
        hashmap:
            *bcd: [abcd]
            a*cd: [abcd]
            ab*d: [abcd]
            abc*: [abcd]
 */