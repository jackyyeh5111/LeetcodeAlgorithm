class MyCircularQueue {
private:
    int* queue;
    int rear;
    int front;
    int size;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue = new int[k];
        for (int i=0; i<k; ++i) queue[i]=0;
        size = k; rear = size; front = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear+1)%size;
        queue[rear] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        if (front==rear) {
            rear=size;
            front=0;
        }
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return queue[(front+1)%size];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return queue[rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return rear==size;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return rear==front;
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
