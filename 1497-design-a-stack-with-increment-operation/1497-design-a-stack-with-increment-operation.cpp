class CustomStack {
public:
    vector<int>arr;
    int size;
    CustomStack(int maxSize) {
        this->size=maxSize;
    }
    
    void push(int x) {
        if(arr.size()<size){
            arr.push_back(x);
        }
    }
    
    int pop() {
        if(arr.empty()){
            return -1;
        }
        int n=arr.size()-1;
        int a=arr[n];
        arr.pop_back();
        return a;
    }
    
    void increment(int k, int val) {
        if(arr.size()>k){
            for(int i=0; i<k; i++){
                arr[i]=arr[i]+val;
            }
        }
        else{
            for(int i=0; i<arr.size(); i++){
                arr[i]=arr[i]+val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */