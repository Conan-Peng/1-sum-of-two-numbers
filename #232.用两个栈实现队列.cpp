class MyQueue {
public:
    //用两个栈来实现队列
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _new.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stackShift();
        int val = _old.top();
        _old.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        stackShift();
        return _old.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _new.empty() && _old.empty();
    }

    void stackShift(){
        if (!_old.empty()) return;
        while (!_new.empty()){
            _old.push(_new.top());
            _new.pop();
        }
    }

private:
    stack<int> _new, _old;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
