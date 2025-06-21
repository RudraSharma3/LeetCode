class MinStack {
private:
    std::stack<int> s;
    std::stack<int> min_s;
public:
    MinStack() {
      
    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty() || val <= min_s.top()){
            min_s.push(val);
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()==min_s.top()){
                min_s.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!min_s.empty()){
            return min_s.top();
        }
        return INT_MAX;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */