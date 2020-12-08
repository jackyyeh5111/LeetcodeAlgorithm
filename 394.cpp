/*
    sanity check with init num: 1 and init string ""
    stack 1: duplicate nums
    stack 2: current sting
    T:O(n)/S:O(n)
*/
class Solution {
public:
    string decodeString(string s)
    {
        stack<int> nums; nums.push(1);
        stack<string> words; words.push("");
        int i=0, n=s.length();
        while (i<n) {
            if (isdigit(s[i])) {
                int num=0;
                while(isdigit(s[i])) num=num*10+(s[i++]-'0');
                nums.push(num);
            }
            else if (s[i]=='[') {words.push(""); i++;}
            else if (s[i]==']') {
                int k=nums.top(); nums.pop();
                string t=words.top(); words.pop();
                while(k>0) {
                    words.top()+=t;
                    k--;
                }
                i++;
            }
            else words.top()+=s[i++];
        }
        return words.top();
    }
};
