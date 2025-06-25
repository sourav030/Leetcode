class MyQueue {
public:
    stack<int> st, st2;

    MyQueue() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
        }
        int ele = st2.top();
        st2.pop();
        return ele;
    }

    int peek() {
        if (st2.empty()) {
            while (!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st.empty() && st2.empty();
    }
};
