class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1,s2;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s1.empty()) {
            while(!s2.empty()) {
                int num=s2.top(); s2.pop();
                s1.push(num);
            }
        }
        int ret=s1.top(); s1.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        int num=pop();
        s1.push(num);
        return num;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
