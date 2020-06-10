
// One pass dynamic programming
class Solution {
public:
    //T: O(N), S:O(N)
    int longestValidParentheses(string s)
    {
        int max_length = 0;
        stack<int> record;
        record.push(-1);
        for (int i=0; i<s.length(); ++i) {
            int top = record.top();
            if (top!=-1&&s[i]==')'&&s[top]=='('){
                record.pop();
                max_length = max(max_length, i-record.top());
            }
            else
                record.push(i);
        }
        return max_length;
    }
};
