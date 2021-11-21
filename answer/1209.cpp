/*
    utilize a queue for k chars comparison
    "deeedbbcccbdaa", k=3
    design a buffer for backward comparison
    <rest> <size k>
    criteria of buffer q:
        all chars must be the same
        fullfill the buffer queue from "rest" buffer as much as we can
    -----
    This data structure canbe simply implemented by string
        random access (by index)
        pop_back
        add to the back of string
    T:O(nk)/S:O(n) as each char
    -----
    Try to reduce TC, think about DP, utilize STACK
    "deeedbbcccbdaa"
     11232121233312
    T:O(n)/S:O(n)
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> mystack; // character, frequency
        for (char &c:s) {
            if (mystack.empty()) mystack.push({c,1});
            else if (mystack.top().first==c) mystack.push({c,mystack.top().second+1});
            else mystack.push({c,1});
            if (mystack.top().second==k) {
                for (int i=0; i<k; ++i)
                    mystack.pop();
            }
        }
        string ans="";
        while (!mystack.empty()) {ans+=mystack.top().first; mystack.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
