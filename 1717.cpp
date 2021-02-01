/*
    cdbcbbaaabab
              ^
    cdbcab
    555 4
    Is there any possibility that we greedy remove ba yet gain less points if we remove ab first?
    aabbaaxybbaabb
                ^ 
    aaxybb
    5555
    -----
    Use 2 stack solution.
    Greedy search larger gain, say x>y, then we search all possible ab first.
    Then scan inverse to find ba.
    T:O(n)/S:O(n)
    -----
    Briefly, we just scan right and left to find consecutive ab or ba.
    Thus we can reduce to S:O(1), i.e. without stack.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        stack<char> mystack;
        string target="";
        int gain=0;
        if (x>y) {target="ab"; gain=x;}
        else {target="ba"; gain=y;}
        int ans=0;
        for (char c:s) {
            if (mystack.size()!=0&&(string(1,mystack.top())+string(1,c))==target) {
                mystack.pop(); 
                ans+=gain;
            }
            else mystack.push(c);
        }
        reverse(target.begin(),target.end());
        gain=x+y-gain;
        stack<char> invstack;
        while (mystack.size()>0) {
            if (invstack.size()!=0&&string(1,mystack.top())+string(1,invstack.top())==target) {
                invstack.pop();
                mystack.pop();
                ans+=gain;
            }
            else {
                invstack.push(mystack.top());
                mystack.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y)
            swap(x, y), reverse(s.begin(), s.end());
        int a = 0, b = 0, ans = 0;
        for (char c : s) {
            if (c == 'a') a++;
            else if (c == 'b') {
                if (a) ans += x, a--;
                else b++;
            }
            else ans += min(a, b) * y, a = b = 0;
        }
        return ans + min(a, b) * y;
    }
}