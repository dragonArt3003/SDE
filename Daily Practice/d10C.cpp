class MinStack {
public:
    /** initialize your data structure here. */
    
    std::stack<int> st;
    std::stack<int> minSt;
    
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty())
            minSt.push(val);
        else
            if (val <= minSt.top())
                minSt.push(val);
    }
    
    void pop() {
        if (!st.empty()){
            int x = st.top();
            st.pop();
            if (x == minSt.top())
                minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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
