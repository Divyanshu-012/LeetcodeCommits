class MyQueue {
    queue<int>pq;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        pq.push(x);
    }
    
    int pop() {
        int val = pq.front();
        pq.pop();
        return val;
    }
    
    int peek() {
        return pq.front();
    }
    
    bool empty() {
        return pq.empty();
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