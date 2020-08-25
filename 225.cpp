/********************** 1 Q **********************/
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n=q.size();
        for (int i=0; i<n-1; ++i) {
            int num=q.front(); q.pop();
            q.push(num);
        }
        int num=q.front(); q.pop();
        return num;
    }

    /** Get the top element. */
    int top() {
        int num=pop();
        q.push(num);
        return num;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/********************** 2 Q **********************/
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n=q2.size();
        for (int i=0; i<n-1; ++i) {
            int num=q2.front(); q2.pop();
            q1.push(num);
        }
        int num=q2.front(); q2.pop();
        swap(q1,q2);
        return num;
    }

    /** Get the top element. */
    int top() {
        int num=pop();
        q2.push(num);
        return num;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
