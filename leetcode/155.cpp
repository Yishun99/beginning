class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (st.empty() || x <= min_st.top())
            min_st.push(x);
        st.push(x);
    }
    
    void pop() {
        int tmp = st.top();
        st.pop();
        if (tmp == min_st.top())
            min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};