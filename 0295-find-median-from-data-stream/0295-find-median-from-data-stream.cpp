class MedianFinder {
public:
    priority_queue<int> maxi; // Max heap for smaller half
    priority_queue<int, vector<int>, greater<int>> mini; // Min heap for larger half

    MedianFinder() {}

    void addNum(int num) {
        if (maxi.empty() || num <= maxi.top()) {
            maxi.push(num);
        } else {
            mini.push(num);
        }

        // Balance the sizes
        if (maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        } else if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if (maxi.size() == mini.size()) {
            return (maxi.top() + mini.top()) / 2.0;
        } else {
            return maxi.top(); 
        }
    }
};
