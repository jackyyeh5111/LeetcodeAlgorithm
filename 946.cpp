/*
    pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    1 2 3
    4 5 3 2 1

    pushed = [1,2,3,4,5],
                      ^
    popped = [4,3,5,1,2]
                    ^
    1 2


    check if 132 or 312 exitsts in terms of index
    use mono stack backward with strict decreasing / increasinig order.
    T:O(n)/S:O(n) 2 pass
    -----
    Directly manipulate as what these stacks act.
    T:O(n)/S:O(n) 1 pass
*/
// T:O(n)/S:O(n) by stack manipulating
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int p=0,n=popped.size();
        stack<int> s;
        for (int i:pushed) {
            s.push(i);
            while (!s.empty()&&popped[p]==s.top()) {
                s.pop(); p++;
            }
        }
        return s.empty();
    }
};

// T:O(n)/S:O(1) by changing the input value
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int i=0,j=0;
        for (int x:pushed) {
            pushed[i++]=x;
            while(i>0&&popped[j]==pushed[i-1]) {i--; j++;}
        }
        return j==popped.size(); // or i==0
    }
};
