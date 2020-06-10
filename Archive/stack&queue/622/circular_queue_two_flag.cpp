class MyCircularQueue {
private:
    int* queue;
    int rear;
    int front;
    int size;
    bool empty;
    bool full;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue = new int[k];
        for (int i=0; i<k; ++i) queue[i]=0;
        rear = 0; front = 0;
        size = k;
        empty=true;
        full=false;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (full) return false;
        queue[rear] = value;
        rear = (rear + 1) % size;
        if (front==rear) full=true;
        empty=false;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (empty) return false;
        front = (front + 1) % size;
        if (front==rear) empty=true;
        full=false;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(empty) return -1;
        return queue[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(empty) return -1;
        return queue[(rear+(size-1))%size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return full;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
