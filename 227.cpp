class Solution {
public:
    int calculate(string s) {
        char prev_op = ' ';
        vector<int> nums;
        string str_num = "";
        for (int idx = 0; idx < s.size(); idx++) {
            char ch = s[idx];
            if (isdigit(ch)) {
                str_num += ch;
                continue;
            }
            else { // operators
                if (ch == ' ') continue;
                
                // adjust last value
                updateVec(nums, str_num, prev_op);
                str_num = "";
                prev_op = ch;
            }
        }
        if (str_num.size())
            updateVec(nums, str_num, prev_op);
        return accumulate(nums.begin(), nums.end(), 0);
    }
    void updateVec(vector<int> &nums, string str_num, char prev_op) {
        int num = stoi(str_num);
        if (prev_op == '/') nums.back() /= num;
        else if (prev_op == '*') nums.back() *= num;
        else if (prev_op == '-') nums.push_back(-num);
        else nums.push_back(num);
    }
};

/* 
    3 + 2 + 2 / 2
    
    stk: 3 -2
 
    3 + 2 * 2
    stk: 3 2 2 
     op: + *
 
 */