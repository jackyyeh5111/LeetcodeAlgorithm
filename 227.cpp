/***** Second Visit *****/
class Solution {
public:
    int calculate(string s)
    {
        unordered_map<char,int> isp,icp;
        isp['+']=2; isp['-']=2; isp['*']=4; isp['/']=4; isp['#']=-1;
        icp['+']=1; icp['-']=1; icp['*']=3; icp['/']=3; icp['#']=-1;
        stack<char> operators;
        operators.push('#');
        stack<int> operands;
        int n=s.length();
        for (int i=0; i<n; ++i) {
            char c=s[i];
            if (c==' ') continue;
            if (isdigit(c)) {
                int num=0;
                while (isdigit(s[i]))
                    num=num*10+(s[i++]-'0');
                --i;
                operands.push(num);
            }
            else {
                while (isp[operators.top()]>icp[c]) {
                    char op=operators.top(); operators.pop();
                    int r=operands.top(); operands.pop();
                    int l=operands.top(); operands.pop();
                    int num=calc(l,r,op);
                    operands.push(num);
                }
                operators.push(c);
            }
        }
        while (operators.size()>1) {
            char op=operators.top(); operators.pop();
            int r=operands.top(); operands.pop();
            int l=operands.top(); operands.pop();
            int num=calc(l,r,op);
            operands.push(num);
        }
        return operands.top();
    }

    int calc(int a, int b, char op)
    {
        if (op=='+') return a+b;
        else if (op=='-') return a-b;
        else if (op=='*') return a*b;
        else return a/b;
    }
};

/***** First Visit *****/
class Solution {
public:
    int calculate(string s)
    {
        unordered_map<char,int> isp;
        isp['+']=2; isp['-']=2; isp['*']=4; isp['/']=4; isp['#']=-1;
        unordered_map<char,int> icp;
        icp['+']=1; icp['-']=1; icp['*']=3; icp['/']=3; icp['#']=-1;
        stack<char> operators; operators.push('#');
        stack<int> operands;
        int n=s.size();
        for (int i=0; i<n; ++i) {
            char c=s[i];
            if (c==' ') continue;
            if (isdigit(c)) {
                int num=0;
                while (isdigit(s[i])) num=num*10+(s[i++]-'0');
                i--;
                operands.push(num);
            }
            else {
                while(isp[operators.top()]>icp[c]) {
                    int b=operands.top(); operands.pop();
                    int a=operands.top(); operands.pop();
                    char op=operators.top(); operators.pop();
                    int num=calc(a,b,op);
                    operands.push(num);
                }
                operators.push(c);
            }
        }
        while (operators.size()>1) {
            int b=operands.top(); operands.pop();
            int a=operands.top(); operands.pop();
            char op=operators.top(); operators.pop();
            int num=calc(a,b,op);
            operands.push(num);
        }
        return operands.top();
    }

    int calc(int a, int b, char op) {
        switch (op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
            default: return -1;
        }
    }
};
