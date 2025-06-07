class MyStack {
    stack<int> st; 

public:
    MyStack() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        int val = st.top(); 
        st.pop();
        return val;
    }

    int top() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
