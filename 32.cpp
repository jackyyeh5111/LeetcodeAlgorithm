/***** Second Visit *****/
/*
    check paranthes valid or not, use a running counter.
    ( ... +1
    ) ... -1
    if -1 skip

    1 pass check bidirection
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int i=0,n=s.length(),c=0,kc=0,k=n-1;
        int ans=0;
        for (int j=0; j<n; ++j) {
            if (s[j]=='(') c++;
            else c--;
            if (c==0) ans=max(ans,j-i+1);
            else if (c<0) {c=0;i=j+1;}

            if(s[n-1-j]==')')kc++;
            else kc--;
            if (kc==0) ans=max(ans,k-n+2+j);
            else if (kc<0) {kc=0;k=n-1-j-1;}
        }
        return ans;
    }
};

/***** First Visit *****/
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
