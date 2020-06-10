class Solution {
public:
    // T:O(n), S:O(n)
    bool isValid(string s)
    {
        unordered_map<char, char> table;
        table['{']='}'; table['(']=')'; table['[']=']';
        stack<char> record;
        for (char c:s) {
            if (c=='{'||c=='('||c=='[')
                record.push(c);
            else {
                if (record.empty()||table[record.top()]!=c) return false;
                record.pop();
            }
        }
        return record.empty();
    }
};
