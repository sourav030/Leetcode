class Solution {
public:
    stack<int> st;
    stack<int> st2;

    Solution() {
        // Nothing needed here
    }

    void push(int x) {
        st.push(x);
        if(st2.empty()) {
            st2.push(x);
        } else {
            st2.push(max(x, st2.top()));
        }
    }

    void pop() {
        if(!st.empty()) {
            st.pop();
            st2.pop();
        }
    }

    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMax() {
        if(st2.empty()) return -1;
        return st2.top();
    }
};

