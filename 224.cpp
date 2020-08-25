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
