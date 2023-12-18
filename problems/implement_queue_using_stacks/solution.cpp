class MyQueue {
public:
    int arr[10000];
    int rear=0;
    int front=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        arr[rear++] = x;
    }
    
    int pop() {
        if(rear==front) return 0;
        return arr[front++];
    }
    
    int peek() {
        if(rear==front) return 0;
        return arr[front];
    }
    
    bool empty() {
        if(rear==front) return true;
        return false;
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