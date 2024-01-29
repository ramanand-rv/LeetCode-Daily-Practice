class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> s2;
        while(!st.empty()){
            s2.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!s2.empty()){
            st.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int tmp = st.top();
        st.pop();
        return tmp;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size() == 0;
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