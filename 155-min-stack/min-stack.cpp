class MinStack {
public:
    stack<int> st;
    stack<int> mst;

    MinStack() : st{}, mst{} {
    }
    
    void push(int val) {
        st.push(val);
        if (mst.empty() || mst.top() >= val) {
            mst.push(val);
        }
    }
    
    void pop() {
        if (st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};
