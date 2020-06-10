#include <stack>
class MyQueue {
public:
    stack<int> stack1, stack2;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.size() == 0) throwEntry();
        int result = stack2.top();
        stack2.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if (stack2.size() == 0) throwEntry();
        return stack2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    void throwEntry()
    {
        while(stack1.size()>0){
            int entry = stack1.top();
            stack1.pop();
            stack2.push(entry);
        }
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
