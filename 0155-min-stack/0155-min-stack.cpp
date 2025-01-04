class MinStack {
private:
    int arr[100005];
    int minStack[100005]; // Auxiliary stack to keep track of minimums
    int topIndex;

public:
    // Constructor
    MinStack() {
        topIndex = -1;
    }
    
    // Push an element onto the stack
    void push(int val) {
        if (topIndex < 100004) { // Check if the stack has space
            topIndex++;
            arr[topIndex] = val;
            if (topIndex == 0) {
                minStack[topIndex] = val; // First element is the minimum
            } else {
                minStack[topIndex] = std::min(minStack[topIndex - 1], val);
            }
        }
    }
    
    // Pop the top element from the stack
    void pop() {
        if (topIndex > -1) { // Check if the stack is not empty
            topIndex--;
        }
    }
    
    // Get the top element of the stack
    int top() {
        if (topIndex > -1) { // Check if the stack is not empty
            return arr[topIndex];
        }
        return -1; // Return a default value when the stack is empty
    }
    
    // Retrieve the minimum element in the stack
    int getMin() {
        if (topIndex > -1) { // Check if the stack is not empty
            return minStack[topIndex];
        }
        return -1; // Return a default value when the stack is empty
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