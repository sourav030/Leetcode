class MinStack {
public:
    vector<int>arr;
    vector<int>minArray;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
         if (minArray.empty()) {
            minArray.push_back(val);
        } else {
            minArray.push_back(min(val, minArray.back()));
        }
    }
    
    void pop() {
        if(!arr.empty()){
            arr.pop_back();
            minArray.pop_back();
        }
    }
    
    int top() {
        if(arr.empty()){
            return -1;
        }
        return arr.back();
    }
    
    int getMin() {
        if(minArray.empty()){
            return -1;
        }
        return minArray.back();
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