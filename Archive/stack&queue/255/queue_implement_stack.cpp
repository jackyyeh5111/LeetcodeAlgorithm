class MyStack {
public:
    queue<int> myQueue;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        myQueue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = myQueue.size();
        for(int i=0; i<size-1;++i){
            int entry = myQueue.front();
            myQueue.pop();
            myQueue.push(entry);
        }
        int result = myQueue.front();
        myQueue.pop();
        return result;
    }

    /** Get the top element. */
    int top() {
        int result = pop();
        myQueue.push(result);
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.size()==0;
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
