/***** Second Visit *****/
/*
    typical stack problem
    use a stack to save incoming characters.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool isValid(string s)
    {
        unordered_map<char,char> table;
        table['(']=')'; table['{']='}'; table['[']=']';
        stack<char> my_stack;
        for (char c:s) {
            if (table.find(c)!=table.end())
                my_stack.push(c);
            else {
                if (my_stack.empty()) return false;
                char t=my_stack.top(); my_stack.pop();
                if (c!=table[t]) return false;
            }
        }
        return my_stack.empty();
    }
};

/***** First Visit *****/
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
