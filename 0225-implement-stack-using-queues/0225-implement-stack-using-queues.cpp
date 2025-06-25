class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size() - 1;
        while (n--) {
            q.push(q.front());
            q.pop();
        }
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        int n = q.size() - 1;
        while (n--) {
            q.push(q.front());
            q.pop();
        }
        int ele = q.front();
        q.push(ele); // Restore the queue
        q.pop();     // Remove the extra front
        return ele;
    }
    
    bool empty() {
        return q.empty();
    }
};
