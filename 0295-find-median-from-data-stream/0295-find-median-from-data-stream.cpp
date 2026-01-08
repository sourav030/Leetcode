class MedianFinder {
public:
    priority_queue<int>mxpq;
    priority_queue<int,vector<int>, greater<int> >mnpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxpq.empty() || num<mxpq.top()){
            mxpq.push(num);
        }
        else{
            mnpq.push(num);
        }
        if(mxpq.size()>mnpq.size()+1){
            mnpq.push(mxpq.top());
            mxpq.pop();
        }
        if(mnpq.size()>mxpq.size()){
            mxpq.push(mnpq.top());
            mnpq.pop();
        }
    }
    
    double findMedian() {
        if(mxpq.size()>mnpq.size()){
            return double (mxpq.top());
        }
        else{
            return double ((mxpq.top()+mnpq.top())/2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */