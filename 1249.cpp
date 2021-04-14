/*
    Greedy delete invalid parentheses
    It costs T:O(n) each time we delete the parentheses.
    T:O(n^2)/S:O(n)
    -----
    Use a delimeter which denotes we are going  to delete it.
    After the first pass, we delete it.
    T:o(n)/S:O(n)
    -----
    Two pass in-place delete
    The first loop remove extra '(' from back to front
    The second loop remove remaining extra ')' from front to back.

    The second loop fill the empty slots in the front. Then we don't have to move anything, just erase unused at the back.
    T:O(n)/S:O(1)
*/
// T:O(n^2)/S:O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char,int>> mystack;
        int n=s.length();
        for (int i=n-1; i>=0; --i) {
            if (isalpha(s[i])) continue;
            else if (s[i]==')') mystack.push({')',i});
            else if (!mystack.empty()) mystack.pop();
            else s.erase(i,1);
        }
        int cnt=0;
        while (!mystack.empty()) {
            s.erase(mystack.top().second-cnt,1); mystack.pop();
            cnt++;
        }
        return s;
    }
};

// T:O(n)/S:O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int i = s.size();
        int balance = 0;
        // remove invalid '('
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ')') balance++;
            else if (s[j] == '(') {
                if (balance == 0) continue;
                balance--;
            }
            s[--i] = s[j];
        }
        int len = 0;
        balance = 0;
        // remove invalid ')'
        for (; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') {
                if (balance == 0) continue;
                balance--;
            }
            s[len++] = s[i];
        }
        s.erase(len);
        return s;
    }
}
