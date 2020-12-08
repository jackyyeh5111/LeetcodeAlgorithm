/***** Second Visit *****/
/*
    Polish Notation
    left->right: stack
    right->left: recursive
    T:O(n)/S:O(n)
*/
// iterative
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        for (auto token:tokens) {
            if (token!="+"&&token!="-"&&token!="*"&&token!="/") s.push(stoi(token));
            else {
                int r=s.top(); s.pop();
                int l=s.top(); s.pop();
                if (token=="+") s.push(l+r);
                else if (token=="-") s.push(l-r);
                else if (token=="*") s.push(l*r);
                else if (token=="/") s.push(l/r);
            }
        }
        return s.top();
    }
};

// recursive
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        string token=tokens.back(); tokens.pop_back();
        if (token!="+"&&token!="-"&&token!="*"&&token!="/") return stoi(token);
        else {
            int r=evalRPN(tokens);
            int l=evalRPN(tokens);
            if (token=="+") return l+r;
            else if (token=="-") return l-r;
            else if (token=="*") return l*r;
            else if (token=="/") return l/r;
            else return -1;
        }
    }
};

/***** First Visit *****/
// iterative
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        /*
            evaluation of posftfix expression:
                left->right: stack iterative
                right->left: tree recursive
            evaluation of prefix expression:
                left->right: tree recursive
                right->left: stack iterative
        */
        stack<int> s;
        for(string token:tokens){
            if (token!="+"&&token!="-"&&token!="*"&&token!="/") s.push(stoi(token));
            else {
                int r=s.top(); s.pop();
                int l=s.top(); s.pop();
                int result=0;
                if (token=="+") result=l+r;
                if (token=="-") result=l-r;
                if (token=="*") result=l*r;
                if (token=="/") result=l/r;
                s.push(result);
            }
        }
        return s.top();
    }

    // bool isNumber(string s)
    // {
    //     int i=0, length=s.length();
    //     if(s[i]=='+'||s[i]=='-') i++;
    //     if (i==length) return false; // +,-
    //     while(i<length){
    //         if (s[i]-'0'<0||s[i]-'0'>9) return false;
    //         i++;
    //     }
    //     return true;
    // }
};

// recursive
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        string token=tokens.back(); tokens.pop_back();
        if (token!="+"&&token!="-"&&token!="*"&&token!="/") return stoi(token);
        int r=evalRPN(tokens), l=evalRPN(tokens);
        if (token=="+") return l+r;
        else if (token=="-") return l-r;
        else if (token=="*") return l*r;
        else return l/r;
    }
};
