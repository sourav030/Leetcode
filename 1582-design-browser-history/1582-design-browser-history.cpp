class BrowserHistory {
public:
    stack<string>past;
    stack<string>future;

    BrowserHistory(string homepage) {
        past.push(homepage);
    }
    
    void visit(string url) {
        future=stack<string>();
        past.push(url);

    }
    
    string back(int steps) {
        while(steps>0 and past.size()>1){
            future.push(past.top());
            past.pop();
            steps--;
        }
        return past.top();
    }
    
    string forward(int steps) {
        while(steps>0 and !future.empty()){
            past.push(future.top());
            future.pop();
            steps--;
        }
        return past.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */