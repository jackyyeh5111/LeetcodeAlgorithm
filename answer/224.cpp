/***** Second Visit *****/
class Solution {
public:
    int calculate(string s)
    {
        unordered_map<char,int> isp,icp;
        isp['+']=2; isp['-']=2; isp['*']=4; isp['/']=4; isp['(']=0;
        icp['+']=1; icp['-']=1; icp['*']=3; icp['/']=3; icp['(']=5; icp[')']=0;
        stack<int> operands;
        stack<char> operators;
        int n=s.length();
        for (int i=0; i<n; ++i) {
            if (s[i]==' ') continue;
            else if (isdigit(s[i])) {
                int num=0;
                while (i<n&&isdigit(s[i])) num=num*10+(s[i++]-'0');
                i--;
                operands.push(num);
            }
            else {
                while (!operators.empty()&&isp[operators.top()]>=icp[s[i]]) {
                    if (isp[operators.top()]==icp[s[i]]) {operators.pop(); break;}
                    else {
                        int b=operands.top(); operands.pop();
                        int a=operands.top(); operands.pop();
                        char op=operators.top(); operators.pop();
                        int num=calc(op,a,b);
                        operands.push(num);
                        cout<<num<<endl;
                    }
                }
                if (s[i]!=')') operators.push(s[i]);
            }
        }
        while(!operators.empty()) {
            int b=operands.top(); operands.pop();
            int a=operands.top(); operands.pop();
            char op=operators.top(); operators.pop();
            int num=calc(op,a,b);
            operands.push(num);
        }

        return operands.top();
    }

    int calc(char op, int a, int b)
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
        unordered_map<char,int> m;
        m['(']=0; m['+']=1; m['-']=1; m[')']=6; m['#']=-1;
        stack<char> operators; operators.push('#');
        stack<int> operands;
        int n=s.length();
        for (int i=0; i<n; ++i) {
            char c=s[i];
            if (c==' ') continue;
            // cout<<c<<endl;
            if (isdigit(c)) {
                int num=0;
                while (isdigit(s[i])) num=num*10+(s[i++]-'0');
                operands.push(num); i--;
            }
            else if (c=='(') operators.push(c);
            else if (c==')') {
                while(operators.top()!='('){
                    char op=operators.top(); operators.pop();
                    int b=operands.top(); operands.pop();
                    int a=operands.top(); operands.pop();
                    operands.push(calc(a,b,op));
                }
                operators.pop();
            }
            else {
                while (m[c]<=m[operators.top()]) {
                    char op=operators.top(); operators.pop();
                    int b=operands.top(); operands.pop();
                    int a=operands.top(); operands.pop();
                    operands.push(calc(a,b,op));
                }
                operators.push(c);
            }
        }
        while(operators.size()>1) {
            char op=operators.top(); operators.pop();
            int b=operands.top(); operands.pop();
            int a=operands.top(); operands.pop();
            operands.push(calc(a,b,op));
        }
        return operands.top();
    }

    int calc(int a, int b, char op)
    {
        if (op=='+') return a+b;
        else return a-b;
    }
};
