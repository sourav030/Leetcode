class MyQueue {
public:
    stack<int> st1, st2;

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (empty()) return -1;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ele = st2.top();
        st2.pop();  
        return ele;
    }

    int peek() {
        if (empty()) return -1;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
