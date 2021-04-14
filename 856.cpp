/*
    approach 0
    We count the number of layers.
    If we meet '(' layers number level++
    else we meet ')' layers number level--

    If we meet "()", we know the number of layer outside,
    so we can calculate the score ans += 1 << level.
    T:O(n)/S:O(1)
    -----
    typical stack usage
    approach 1
    approach 2
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int scoreOfParentheses(string S)
    {
        int level=0,ans=0,n=S.length();
        for (int i=0; i<n; ++i) {
            if (S[i]=='(') level++;
            else level--;
            if (S[i]==')'&&S[i-1]=='(') ans+=(1<<level);
        }
        return ans;
    }
};

class Solution {
public:
    int scoreOfParentheses(string S)
    {
        stack<int> mystack;
        for (char c:S) {
            if (c=='(') mystack.push(-1);
            else {
                if (mystack.top()==-1) {
                    mystack.pop(); mystack.push(1);
                }
                else {
                    int k=0;
                    while(mystack.top()!=-1) {
                        k+=mystack.top();
                        mystack.pop();
                    }
                    mystack.pop();
                    mystack.push(k*2);
                }
            }
        }
        int ans=0;
        while(!mystack.empty()) {ans+=mystack.top(); mystack.pop();}
        return ans;
    }
};

class Solution {
public:
    int scoreOfParentheses(string S)
    {
        stack<int> stack;
        int cur = 0;
        for (char i : S)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur*2, 1);
                stack.pop();
            }
        return cur;
    }
};
