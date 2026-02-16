class MyStack {
public:
    
    queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        vector<int>arr;
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        int ele=arr.back();
        arr.pop_back();
        for(auto ele:arr){
            q.push(ele);
        }
        return ele;
    }
    
    int top() {
        int x=pop();

        if(x==-1){
            return x;
        }
        q.push(x);
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */